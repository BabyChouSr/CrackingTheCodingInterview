package ChatServer;
import java.util.ArrayList;

public class User {
    String name;
    ArrayList <User> friends;
    ArrayList <Chat> chats;
    String number;
    int uid;
    User(String name, String number, int uid) {
        this.name = name;
        this.number = number;
        this.uid = uid;
        friends = new ArrayList<User>();
    }

    public void addFriend(User user) {
        friends.add(user);
    }

    public void removeFriend(User user) {
        friends.remove(user);
    }

    public void createChat()  {
        
    }

}
