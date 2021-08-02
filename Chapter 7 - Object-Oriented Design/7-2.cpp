// Call Center
// ! Redo in the future
#include <iostream>
#include <vector>

using namespace std;

class Employee {
    private: 
        bool available;
        int priority;
    
    public:
        Employee() : available(true), priority(0) {}
        Employee(int priority) : available(true), priority(priority) {}
        void markUnavailable() {available = false;}
        void markAvailable() {available = true;}
        bool getAvailability() {return available;}
        int getPriority() {return priority;}
};

class CallCenter {
    private:
        vector<Employee> employees;

    public:
        CallCenter() : employees(vector<Employee> ()) {}
        CallCenter(vector <Employee> employees) : employees(employees) {}
        Employee dispatchCall() {
            bool respondentFound = false;

            // Respondent
            for (Employee e : employees) {
                if (e.getPriority() == 1 && e.getAvailability()) {
                    return e;
                }
            }

            //Manager
            if (!respondentFound) {
                for (Employee e : employees) {
                    if (e.getPriority() == 2 && e.getAvailability()) {
                        return e;
                    }
                }
            }

            //Director
            if (!respondentFound) {
                for (Employee e : employees) {
                    if (e.getPriority() == 3 && e.getAvailability()) {
                        return e;
                    }
                }
            }
        } 
};