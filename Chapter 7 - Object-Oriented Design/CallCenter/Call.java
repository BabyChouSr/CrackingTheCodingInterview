package CallCenter;

public class Call {
    int startTime;
    int endTime;
    String description;
    Status status;
    Call (int startTime, int endTime, String description, Status status) {
        this.startTime = startTime;
        this.endTime = endTime;
        this.description = description;
        this.status = status;
    }

    public void setStatus(Status status) {
        this.status = status;
    }
}
