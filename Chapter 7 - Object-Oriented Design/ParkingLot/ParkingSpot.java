package ParkingLot;

public class ParkingSpot {
    private boolean free;
    private Vehicle vehicle;
    private String number;
    private ParkingSpotType type;

    ParkingSpot(String number, ParkingSpotType type) {
        this.free = true;
        this.vehicle = null;
        this.number = number;
        this.type = type;
    }
    public boolean isFree() {
        return free;
    }

    public addVehicle(Vehicle vehicle) {
        this.vehicle = vehicle;
        this.free = false;
    }

    public removeVehicle(Vehicle vehicle) {
        this.vehicle = null;
        this.free = true;
    }
}

public class CompactSpot extends ParkingSpot {
    public CompactSpot() {
        super("compact", ParkingSpotType.COMPACT);
    }
}

public class LargeSpot extends ParkingSpot {
    public LargeSpot() {
        super("large", ParkingSpotType.LARGE);
    }
}

public class Handicapped extends ParkingSpot {
    public Handicapped() {
        super("handicapped", ParkingSpotType.HANDICAPPED);
    }
}

public class Motorcycle extends ParkingSpot {
    public Motorcycle() {
        super("motorcycle", ParkingSpotType.MOTORCYCLE);
    }
}
