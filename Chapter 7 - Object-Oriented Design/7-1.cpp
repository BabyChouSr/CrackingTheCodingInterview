// Deck of Cards

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

using namespace std;

class Suit {
    // Club (0), Diamond (1), Heart (2), Spade (3)
    private:
        int value;
    
    public:
        Suit(int value) : value(value) {}
        int getValue() {return value;}
};

class Card {
    public: 
        bool available = true;
        int faceValue;
        Suit suit;
        Card(int faceValue, Suit suit) : faceValue(faceValue), suit(suit) {}
        int value() {return faceValue;}
        bool getAvailability() {return available;}
        void markUnavailable() {available = false;}
        void markAvaialable() {available = true;}

};

class Hand {
    private:
        vector<Card> cards = vector <Card> ();

    public:
        int score() {
            int score = 0;
            for (Card card: cards) {
                score += card.value();
            }
            return score;
        }

        void addCard(Card card) {
            cards.push_back(card);
        }

        vector<Card> getHand() {
            return cards;
        }
};

class Deck {
    private:
        vector<Card> cards;
        int dealtIndex = 0; // Keeps track of number of cards dealt

    public:
        Deck(vector<Card> cards) : cards(cards) {}

        void shuffleDeck() {
            int seed = chrono::system_clock::now().time_since_epoch().count();
            shuffle(cards.begin(), cards.end(), default_random_engine(seed));
        }

        int remainingCards() {
            return cards.size() - dealtIndex;
        }

        Card dealCard() {
            shuffleDeck();
            for (Card card: cards) {
                if (card.getAvailability()) {
                    return card;
                    dealtIndex++;
                }
            }
            cout << "Empty Deck" << endl;
        }   
};

class BlackJackCard : public Card
{
    public: 
        BlackJackCard(int c, Suit s) : Card(c,s) {} // Calls Super Constructor

        bool isAce() {
            return faceValue == 1;
        }

        bool isFaceCard() {
            return faceValue >= 11 && faceValue <= 13;
        }

        int minValue() {
            if (isAce()) {return 1;}
            else {return faceValue;}
        }

        int maxValue() {
            if (isAce()) {return 11;}
            else {return faceValue;}
        }

        int value () {
            if (isAce()) {return 1;}
            else if (isFaceCard()) {return 10;}
            else {return faceValue;}
        }


};

class BlackJackHand : public Hand {
    private:
        void addCardToList (BlackJackCard *card, vector<int> & scores) {
            if (scores.empty()) {
                scores.push_back(0);
            }
            int length = scores.size();
            for (int i = 0; i < length; i++) {
                int score = scores[i];
                scores[i] = score + card->minValue();
                if (card->minValue() != card->maxValue()) {
                    scores.push_back(score + card->maxValue());
                }

            }

        }

        vector<int> possibleScores() {
            vector<int> scores;
            // ! might need to fix since not working rn
            for (BlackJackCard *card: cards) { // referring to the blackjackcard
                addCardToList(card, scores);
            }
            return scores;
        }


    public:
        int score() {
            vector <int> scores = possibleScores();
            int maxUnder = std::numeric_limits<int>::min();
            int minOver = std::numeric_limits<int>::max();
            for (int score: scores) {
                if (score > 21 && score < minOver) {
                    minOver = score;
                }
                else if (score <= 21 && score > maxUnder) {
                    maxUnder = score;
                }
            }
            return (maxUnder == numeric_limits<int>::min()) ? minOver : maxUnder;
        }

};