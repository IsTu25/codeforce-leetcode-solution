#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    string EmpName;
    int ID;
    float BaseSalary;
    int JoiningYear;

    float calculateTotalSalary() const {
        float transportAllowance = 0.10 * BaseSalary;
        float housingAllowance = 0.30 * BaseSalary;
        float miscAllowance = 0.10 * BaseSalary;
        float totalSalary = BaseSalary + transportAllowance + housingAllowance + miscAllowance;
        return totalSalary;
    }

    float calculateBonus(string status, int yearsOfService) const {
        float updatedBaseSalary = BaseSalary;
        for (int i = 0; i < yearsOfService; i++) {
            updatedBaseSalary += 0.03 * updatedBaseSalary;
        }

        if (status == "Low") {
            return 0.05 * updatedBaseSalary;
        } else if (status == "Moderate") {
            return 0.10 * updatedBaseSalary;
        } else if (status == "High") {
            return 0.15 * updatedBaseSalary;
        } else {
            return 0;
        }
    }

    string getStatus(int age) const {
        float totalSalary = calculateTotalSalary();
        
        if (age <= 25) {
            if (totalSalary <= 20000) {
                return "Low";
            } else {
                return "Moderate";
            }
        } else {
            if (totalSalary <= 21000) {
                return "Low";
            } else if (totalSalary > 21000 && totalSalary <= 60000) {
                return "Moderate";
            } else {
                return "High";
            }
        }
    }

public:
    void FeedInfo(string name, int id, float baseSalary, int joiningYear) {
        EmpName = name;
        ID = id;
        BaseSalary = baseSalary;
        JoiningYear = joiningYear;
    }

    void ShowInfo() {
        int currentYear = 2024;
        int age = currentYear - JoiningYear;
        string status = getStatus(age);
        int yearsOfService = currentYear - JoiningYear;

        cout << "Employee Name: " << EmpName << endl;
        cout << "Employee ID: " << ID << endl;
        cout << "Base Salary: BDT " << BaseSalary << endl;
        cout << "Joining Year: " << JoiningYear << endl;
        cout << "Years of Service: " << yearsOfService << endl;
        cout << "Total Salary: BDT " << calculateTotalSalary() << endl;
        cout << "Employee Status: " << status << endl;
        cout << "Bonus: BDT " << calculateBonus(status, yearsOfService) << endl;
    }
};

int main() {
    Employee emp;
    emp.FeedInfo("John Doe", 101, 18000.0, 2020);
    emp.ShowInfo();

    return 0;
}
