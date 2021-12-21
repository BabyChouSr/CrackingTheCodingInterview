package CallCenter;
import java.util.ArrayList;
import java.util.Queue;

public class CallCenter {
    String address; 
    ArrayList <Employee> employees;
    ArrayList <Call> calls;
    Queue <Call> callQueue;

    CallCenter(String address) {
        this.address = address;
        this.employees = new ArrayList<Employee>();
    }

    public void addEmployee(Employee employee) {
        employees.add(employee);
    }

    public Employee dispatchCall(Call call) {
        // Check Fresher first
        for (Employee employee: employees) {
            if (employee.getType() == EmployeeType.FRESHER && employee.getStatus() == Status.FREE) {
                call.setStatus(Status.BUSY);
                employee.setStatus(Status.BUSY);
                return employee;
            }
        }

        for (Employee employee: employees) {
            if (employee.getType() == EmployeeType.TL && employee.getStatus() == Status.FREE) {
                call.setStatus(Status.BUSY);
                employee.setStatus(Status.BUSY);
                return employee;
            }
        }
        for (Employee employee: employees) {
            if (employee.getType() == EmployeeType.PM && employee.getStatus() == Status.FREE) {
                call.setStatus(Status.BUSY);
                employee.setStatus(Status.BUSY);
                return employee;
            }
        }
        
        System.out.println("No one is available right now. Please wait.");
        callQueue.add(call);
        return null;
    }

    public Employee dispatch_queued_call() {
        //Implementation not shown
    }
}
