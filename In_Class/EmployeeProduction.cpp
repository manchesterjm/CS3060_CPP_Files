#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    string name; // employee’s name
    int number; // employee’s ID number
    string hireDate; // date hired
    string disabled; // to handle disabled workers

public:
    // default constructor: name="", number=0, hireDate=""
    Employee() : name(""), number(0), hireDate(""), disabled("no") {}

    // overloaded constructor: initialize all fields
    Employee(string empName, int empNumber, string empHireDate, string isDisabled) : name(empName), number(empNumber), hireDate(empHireDate), disabled(isDisabled) {}

    // ********* setters *********

    // setName: store empName
    void setName(string empName) {
        name = empName;
    }

    // setNumber: store empNumber
    void setNumber(int empNumber) {
        number = empNumber;
    }

    // setHireDate: store empHireDate
    void setHireDate(string empHireDate) {
        hireDate = empHireDate;
    }

    // set if disabled
    void setDisabled(string isDisabled) {
        disabled = isDisabled;
    }

    // ********* getters **********

    // getName: return name
    string getName() const {
        return name;
    }

    // getNumber: return number
    int getNumber() const {
        return number;
    }

    // getHireDate: return hireDate
    string getHireDate() const {
        return hireDate;
    }

    // get disabled status
    string getDisabled() const {
        return disabled;
    }
};

// makes a worker extended off of employee
class ProductionWorker : public Employee {
private:
    int shift; // 1 = day, 2 = night
    double hourlyRate; // pay per hour

public:
    // default constructor: calls Employee(), then shift=1 which is day shift, hourlyRate=0.0
    ProductionWorker() : Employee(), shift(1), hourlyRate(0.0) {}

    // overloaded constructor: calls Employee(...), then initializes shift and rate
    // but since the worker class only has vars for shift and hourly rate, we need
    // to extend our class from employee so we can access employee name, the hire date, and the
    // employee number
    ProductionWorker(string empName, int empNumber, string empHireDate, int workShift, double payRate, string isDisabled)
        : Employee(empName, empNumber, empHireDate, isDisabled), shift(workShift), hourlyRate(payRate) {}

    // ********* setters *********

    // setShift: store workShift
    void setShift(int workShift) {
        shift = workShift;
    }

    // setHourlyRate: store payRate
    void setHourlyRate(double payRate) {
        hourlyRate = payRate;
    }

    // ********* getters **********

    // if we need to return other information about the employee that is not contained in
    // the worker class, then we need to call those member functions from the employee class

    // getShift: return shift
    int getShift() const {
        return shift;
    }

    // getHourlyRate: return hourlyRate
    double getHourlyRate() const {
        return hourlyRate;
    }
};

int main() {
    // create a worker named after me
    ProductionWorker worker("Josh Manchester", 1001, "2025-05-11", 2, 50.00, "no");
    // then create a worker that tests out the default constructor
    ProductionWorker worker2; 

    // display using getters
    cout << "Preformated worker info:" << endl;
    cout << "\nEmployee Name: " << worker.getName() << endl;
    cout << "Employee Number: " << worker.getNumber() << endl;
    cout << "Hire Date: " << worker.getHireDate() << endl;
    cout << "Is Disabled?: " << worker.getDisabled() << endl;
    // this line checks to see what int is stored in shift
    // if it is 1 then we display Day, of not 1 then display Night
    // in this case we can have any int stored other than 1 to mean night
    cout << "Shift: " << (worker.getShift() == 1 ? "Day" : "Night") << endl;
    cout << "Hourly Rate: $" << worker.getHourlyRate() << "/hr" << endl;

    // update using setters
    worker.setShift(1);
    worker.setHourlyRate(24.00);

    // display updated
    cout << "\nAfter updating shift and pay rate:" << endl;
    cout << "\nShift: " << (worker.getShift() == 1 ? "Day" : "Night") << endl;
    cout << "Hourly Rate: $" << worker.getHourlyRate() << "/hr" << endl;

    // display the default info that was set by the default constructor
    cout << "\nDefault worker info:" << endl;
    cout << "\nEmployee Name: " << worker2.getName() << endl;
    cout << "Employee Number: " << worker2.getNumber() << endl;
    cout << "Hire Date: " << worker2.getHireDate() << endl;
    cout << "Is Disabled?: " << worker2.getDisabled() << endl;
    cout << "Shift: " << (worker2.getShift() == 1 ? "Day" : "Night") << endl;
    cout << "Hourly Rate: $" << worker2.getHourlyRate() << "/hr" << endl;

    // update worker2 using setters
    worker2.setShift(2);
    worker2.setHourlyRate(26.00);
    worker2.setName("New Guy");
    worker2.setNumber(1002);
    worker2.setHireDate("2025-05-12");
    worker2.setDisabled("yes");

    // display updated worker2 info
    cout << "\nAfter updating all the worker fields using setters:" << endl;
    cout << "\nEmployee Name: " << worker2.getName() << endl;
    cout << "Employee Number: " << worker2.getNumber() << endl;
    cout << "Hire Date: " << worker2.getHireDate() << endl;
    cout << "Is Disabled?: " << worker2.getDisabled() << endl;
    cout << "Shift: " << (worker2.getShift() == 1 ? "Day" : "Night") << endl;
    cout << "Hourly Rate: $" << worker2.getHourlyRate() << "/hr" << endl;

    return 0;
}