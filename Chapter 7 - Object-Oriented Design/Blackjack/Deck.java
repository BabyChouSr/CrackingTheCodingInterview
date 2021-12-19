package Blackjack;
import java.util.ArrayList;

public class Deck extends BlackJackCard{
    private ArrayList<BlackJackCard> cards;

    Deck() {
        this.cards = new ArrayList <BlackJackCard> ();
        for (int i = 1; i <= 13; i++) {
            for (Suit suit: Suit.values()) {
                cards.add(new BlackJackCard(suit, i));
            }
        }
    }

    public ArrayList<BlackJackCard> getCards() {
        return this.cards;
    }
}
