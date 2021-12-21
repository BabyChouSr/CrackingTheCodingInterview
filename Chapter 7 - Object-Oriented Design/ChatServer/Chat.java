package ChatServer;

import java.util.HashMap;
import java.util.ArrayList;

public class Chat {
    int cid;
    HashMap<User, ArrayList<Message> > users;

    public Chat(int cid) {
        this.cid = cid;
        users = new HashMap<User, ArrayList<Message> >();
    }

    public void addUser(User user) {
        users.put(user, new ArrayList<Message>());
    }
    public void removeUser(User user) {
        users.remove(user);
    }

    public void addMessage(User user, Message message) {
        users.get(user).add(message);
    }
    
    public void removeMessage(User user, Message message) {
        users.get(user).remove(message);
    }
}
