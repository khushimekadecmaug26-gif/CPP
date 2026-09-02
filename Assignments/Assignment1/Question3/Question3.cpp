#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Employee
{
private:
    int empId;
    string name;
    string department;
    char grade;
    double basicSalary;
    bool isActive;

    static int employeeCount;

public:

 
    Employee()
    {
        employeeCount++;
        empId = 1000 + employeeCount;

        name = "Unknown";
        department = "Engineering";
        grade = 'D';
        basicSalary = 10001;
        isActive = true;
    }

  
    void setName(const string& n)
    {
        if (!n.empty())
            name = n;
        else
            cout << "ERROR: Name cannot be empty." << endl;
    }

  
    void setDepartment(const string& dept)
    {
        if (dept == "Engineering" ||
            dept == "HR" ||
            dept == "Finance" ||
            dept == "Operations")
        {
            department = dept;
        }
        else
        {
            cout << "ERROR: '" << dept
                 << "' is not a registered department." << endl;
        }
    }

    // Set Grade
    void setGrade(char g)
    {
        if (g == 'A' || g == 'B' || g == 'C' || g == 'D')
        {
            grade = g;
        }
        else
        {
            cout << "ERROR: Invalid grade '" << g
                 << "'. Accepted values: A, B, C, D."
                 << endl;
        }
    }

    // Set Salary
    void setBasicSalary(double salary)
    {
        if (salary > 10000 && salary < 500000)
        {
            basicSalary = salary;
        }
        else
        {
            cout << "ERROR: Salary must be greater than Rs.10,000 "
                 << "and less than Rs.5,00,000. Value rejected."
                 << endl;
        }
    }

    // Deactivate employee
    void deactivate()
    {
        isActive = false;
    }


    int getEmpId() const
    {
        return empId;
    }

    string getName() const
    {
        return name;
    }

    string getDepartment() const
    {
        return department;
    }

    char getGrade() const
    {
        return grade;
    }

    double getBasicSalary() const
    {
        return basicSalary;
    }

    bool getIsActive() const
    {
        return isActive;
    }

    static int getEmployeeCount()
    {
        return employeeCount;
    }

    double computeAllowances() const
    {
        if (grade == 'A')
            return basicSalary * 0.40;
        else if (grade == 'B')
            return basicSalary * 0.30;
        else if (grade == 'C')
            return basicSalary * 0.20;
        else
            return basicSalary * 0.10;
    }


    double computeGrossSalary() const
    {
        return basicSalary + computeAllowances();
    }

    double computeTax() const
    {
        double gross = computeGrossSalary();

        if (gross <= 50000)
            return 0;

        else if (gross <= 100000)
            return (gross - 50000) * 0.10;

        else
            return 5000 + (gross - 100000) * 0.20;
    }

    double computeNetSalary() const
    {
        return computeGrossSalary() - computeTax();
    }

    
    void printPayslip() const
    {
        if (!isActive)
        {
            cout << name
                 << " is inactive. Payroll skipped."
                 << endl;
            return;
        }

        int percentage;

        if (grade == 'A')
            percentage = 40;
        else if (grade == 'B')
            percentage = 30;
        else if (grade == 'C')
            percentage = 20;
        else
            percentage = 10;

        cout << fixed << setprecision(2);

        cout << "\n============================================" << endl;
        cout << "        EMPLOYEE PAYSLIP" << endl;
        cout << "============================================" << endl;

        cout << "Emp ID        : " << empId << endl;
        cout << "Name          : " << name << endl;
        cout << "Department    : " << department << endl;
        cout << "Grade         : " << grade << endl;
        cout << "Status        : Active" << endl;

        cout << "--------------------------------------------" << endl;

        cout << "Basic Salary  : Rs. " << basicSalary << endl;

        cout << "Allowances ("
             << percentage << "%) : Rs. "
             << computeAllowances() << endl;

        cout << "Gross Salary  : Rs. "
             << computeGrossSalary() << endl;

        cout << "--------------------------------------------" << endl;

        cout << "Tax Deduction : Rs. "
             << computeTax() << endl;

        cout << "Net Salary    : Rs. "
             << computeNetSalary() << endl;

        cout << "============================================" << endl;
    }


    void acceptDetails()
    {
        string inputName;
        string inputDept;
        char inputGrade;
        double inputSalary;

        cout << "Enter name: ";
        getline(cin >> ws, inputName);
        setName(inputName);

        cout << "Enter department: ";
        getline(cin >> ws, inputDept);
        setDepartment(inputDept);

        cout << "Enter grade: ";
        cin >> inputGrade;
        setGrade(inputGrade);

        cout << "Enter basic salary: ";
        cin >> inputSalary;
        setBasicSalary(inputSalary);
    }
};

// Initialize static member
int Employee::employeeCount = 0;


int main()
{
    
    Employee e1;
    Employee* e2 = new Employee();
    Employee* e3 = new Employee();

    // Accept details
    e1.acceptDetails();
    e2->acceptDetails();
    e3->acceptDetails();



    // Print payslips
    e1.printPayslip();
    e2->printPayslip();
    e3->printPayslip();

    // Deactivate employee 3
    e3->deactivate();

    if (!e3->getIsActive())
    {
        cout << e3->getName()
             << " is no longer active. Payroll skipped."
             << endl;
    }

    // Display total employees
    cout << "Total Employees : "
         << Employee::getEmployeeCount()
         << endl;

    // Delete heap objects
    delete e2;
    delete e3;

    return 0;
}