#include <iostream>
#include <string>
using namespace std;

class Employee 
{
private:
    string name;
    int employeeID;
    double salary;

public:
    Employee(string empName, int empID, double empSalary) 
	{
        name = empName;
        employeeID = empID;
        salary = empSalary;
    }

    void setSalaryBasedOnPerformance(int performanceRating)
	 {
        if (performanceRating == 1) 
		{
            salary += salary * 0.20;
        } else if (performanceRating == 2)
		 {
            salary += salary * 0.10; 
        } else if (performanceRating == 3) 
		{
            salary += salary * 0.05;
        } else {
            cout << "No salary increase for poor performance." << endl;
        }
    }
    void displayEmployeeDetails() 
	{
        cout << "Employee Name: " << name << endl;
        cout << "Employee ID: " << employeeID << endl;
        cout << "Current Salary: $" << salary << endl;
    }
};

int main() {

    Employee emp1("manubhai", 12345, 50000.00);
    cout << "Initial Employee Details:" << endl;
    emp1.displayEmployeeDetails();
    int performanceRating;
    cout << "\nEnter performance rating (1-Excellent, 2-Good, 3-Average, 4-Poor): ";
    cin >> performanceRating;

    emp1.setSalaryBasedOnPerformance(performanceRating);
    cout << "\nUpdated Employee Details:" << endl;
    emp1.displayEmployeeDetails();

    return 0;
}
