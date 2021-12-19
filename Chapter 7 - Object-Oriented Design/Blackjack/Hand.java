package Blackjack;
import java.util.ArrayList;

public class Hand {
    private ArrayList<BlackJackCard> cards;
    
    public ArrayList <Integer> getScore() {
        ArrayList <Integer> score = new ArrayList <Integer> ();
        score.add(0);
        for (BlackJackCard card: cards) {
           ArrayList<Integer> newTotal = new ArrayList<Integer>();
           for (int curr: score) {
               newTotal.add(card.getGameValue() + curr);
               if (card.getGameValue() == 1) {
                   newTotal.add(11 + curr);
               }
           }
           score = newTotal;
        }
        return score;

    }

    public Hand(BlackJackCard c1, BlackJackCard c2) {
        this.cards = new ArrayList <BlackJackCard> ();
        this.cards.add(c1);
        this.cards.add(c2);
    }

    public void addCard(BlackJackCard c) {
        this.cards.add(c);
    }

    public int resolveScore() {
        ArrayList <Integer> score = getScore();
        int max = 0;
        for (int curr: score) {
            if (curr > max && curr <= 21) {
                max = curr;
            }
        }
        return max;
    }
}
