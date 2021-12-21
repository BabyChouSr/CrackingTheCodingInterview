package ChatServer;

public class Message {
    String text;
    String link_to_image;
    String time;

    Message(String text, String link_to_image, String time) {
        this.text = text;
        this.link_to_image = link_to_image;
        this.time = time;
    }
}
