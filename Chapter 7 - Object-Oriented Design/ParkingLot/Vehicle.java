package ParkingLot;

public class Vehicle {
    String licensePlate;
    String type;
    ParkingTicket ticket;

    Vehicle(String licensePlate, String type, ParkingTicket ticket) {
        this.licensePlate = licensePlate;
        this.type = type;
        this.ticket = ticket;
    }

    public void assignTicket(ParkingTicket ticket) {
        this.ticket = ticket;
    }
}

public class Van extends Vehicle {
    Van(String licensePlate, String type, ParkingTicket ticket) {
        super(licensePlate, type, ticket);
    }
}

public class Car extends Vehicle {
    Car(String licensePlate, String type, ParkingTicket ticket) {
        super(licensePlate, type, ticket);
    }
}

public class Truck extends Vehicle {
    Truck(String licensePlate, String type, ParkingTicket ticket) {
        super(licensePlate, type, ticket);
    }
}


