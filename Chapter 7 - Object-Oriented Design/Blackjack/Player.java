package Blackjack;
import java.util.List;
import java.util.ArrayList;

public enum AccountStatus {
    ACTIVE, SUSPENDED, BANNED
}

public abstract class BasePlayer {
    private String id;
    private String password;
    private double balance;
    private AccountStatus status;
    private Person person;
    private List<Hand> hands;
  
    public boolean resetPassword();
  
    public List<Hand> getHands() {
      return hands;
    }
  
    public void addHand(Hand hand) {
      hands.add(hand);
    }
  
    public void removeHand(Hand hand) {
      hands.remove(hand);
    }
}


public class Player extends BasePlayer {
  private int bet;
  private int totalCash;

  public Player(Hand hand) {
    this.hands = new ArrayList<Hand>();
    this.hands.add(hand);
  }
}