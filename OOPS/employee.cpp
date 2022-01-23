Qn:

Write a program by creating an 'Employee' class having the following functions and print the final salary.
1 - 'getInfo()' which takes the salary, number of hours of work per day of employee as parameters
2 - 'AddSal()' which adds $10 to the salary of the employee if it is less than $500.
3 - 'AddWork()' which adds $5 to the salary of the employee if the number of hours of work per day is more than 6 hours.


Solution:

#include<bits/stdc++.h>
using namespace std;
class Employee{
    int salary;
    int hours;
    
    public:
    void getInfo(){
        cin >> salary >> hours;
    }
    void addSalary(){
        if(salary < 500){
            salary += 10;
        }
    }
    void addWork(){
        if(hours > 6){
            salary += 5;
        }
    }
    void getSalary(){
        cout << salary;
    }
};
int main()
{
    Employee e1;
    e1.getInfo();
    e1.addSalary();
    e1.addWork();
    e1.getSalary();
    return 0;
}
