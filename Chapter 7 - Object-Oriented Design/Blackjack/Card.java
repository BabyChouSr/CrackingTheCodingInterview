package Blackjack;

public enum Suit {
    CLUBS, DIAMONDS, HEARTS, SPADES
}

public class Card {
    private Suit suit;
    private int cardValue;

    public Card(Suit suit, int cardValue) {
        this.suit = suit;
        this.cardValue = cardValue;
    }

    public getSuit() {
        return this.suit;
    }

    public getCardValue() {
        return this.cardValue;
    }
}
