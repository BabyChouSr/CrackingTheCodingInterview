package CallCenter;

public class Employee {
    private String name;
    private EmployeeType type;
    private Status status;
    
    Employee(String name, EmployeeType type, Status status) {
        this.name = name;
        this.type = type;
        this.status = status;
    }
    public EmployeeType getType() {
        return type;
    }
    public void setStatus(Status status) {
        this.status = status;
    }
    public Status getStatus() {
        return status;
    }
}

public class PM extends Employee {
    PM(String name) {
        super(name, EmployeeType.PM, Status.AVAILABLE);
    }
}

public class TL extends Employee {
    TL(String name) {
        super(name, EmployeeType.TL, Status.AVAILABLE);
    }
}

public class Fresher extends Employee {
    Fresher(String name) {
        super(name, EmployeeType.FRESHER, Status.AVAILABLE);
    }
}