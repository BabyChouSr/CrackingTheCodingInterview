package Blackjack;

public class BlackJackCard extends Card{
    private int gameValue;
    BlackJackCard(Suit suit, int cardValue) {
        super(suit, cardValue);
        this.gameValue = cardValue;
        if (gameValue > 10) {
            gameValue = 10;
        }
    }

    public int getGameValue() {
        return this.gameValue;
    }
}
