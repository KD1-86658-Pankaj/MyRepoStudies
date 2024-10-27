#include <iostream>
#include <typeinfo>
using namespace std;
class Employee
{
    int id;
    double salary;
    
public:
    Employee()
    {
        this->id = 0;
        this->salary = 0;
    }
    Employee(int id, double salary)
    {
        this->id = id;
        this->salary = salary;
    }

    virtual void accept()
    {
        cout << "Enter your ID :----" << endl;
        cin >> this->id;
        cout << "Enter your salary :----" << endl;
        cin >> this->salary;
    }
    virtual void display()
    {
        cout << "ID-->" << this->id << endl;
        cout << "Salary-->" << this->salary << endl;
    }

protected:
    void setId(int id)
    {
        this->id = id;
    }
    int getId()
    {
        return this->id;
    }
    void setSalary(double salary)
    {
        this->salary = salary;
    }
    double getSalary()
    {
        return this->salary;
    }
};
class Manager : virtual public Employee
{
    double bonus;

public:
    Manager()
    {
        this->bonus = 0;
    }
    Manager(int id, double salary, double bonus) : Employee(id, salary)
    {
        this->bonus = bonus;
    }
    void setBonus(double bonus)
    {
        this->bonus = bonus;
    }
    double getBonus()
    {
        return this->bonus;
    }
    virtual void accept()
    {
        Employee::accept();
        acceptManager();
    }
    virtual void display()
    {
        Employee::display();
        displayManager();
    }
    void acceptManager()
    {
        cout << "Enter Bonus :--" << endl;
        cin >> this->bonus;
    }
    void displayManager()
    {
        cout << "Bonus-->" << this->bonus << endl;
    }
};

class SalesMan : virtual public Employee
{
    double commision;

public:
    SalesMan()
    {
        this->commision = 0;
    }
    SalesMan(int id, double salary, double comission) : Employee(id, salary)
    {
        this->commision = comission;
    }
    void setCommsion(double commision)
    {
        this->commision = commision;
    }
    double getCommision()
    {
        return this->commision;
    }
    virtual void accept()
    {
        Employee::accept();
        acceptSalesman();
    }
    virtual void display()
    {
        Employee::display();
        displaySalesman();
    }
    void acceptSalesman()
    {
        cout << "Enter commision :--" << endl;
        cin >> this->commision;
    }
    void displaySalesman()
    {
        cout << "Bonus-->" << this->commision << endl;
    }
};
class SalesManager : public Manager, public SalesMan
{
public:
    SalesManager()
    {
    }
    void accept()
    {
        Employee::accept();
        Manager::accept();
        SalesMan::accept();
    }
    void display()
    {
        Employee::display();
        displayManager();
        displaySalesman();
    }
};

int main()
{
    bool flag = true;
    int choice;
    Employee *arr[5];
    int index = 0;
    while (flag)
    {

        cout << "0.EXIT" << endl;
        cout << "1.Accept Manager" << endl;
        cout << "2.Accept Salesman" << endl;
        cout << "3.Accept SalesManager" << endl;
        cout << "4.Display the count of all employees with respect to designation" << endl;
        cout << "5.Display All Managers" << endl;
        cout << "6.Display All Salesman" << endl;
        cout << "7.Display All SalesManager" << endl;
        cout << "#----------#" << endl;
        cout << "Enter Choice -: ";
        cin >> choice;
        switch (choice)
        {
        case 0:
            flag = false;
            break;
        case 1:
            if (index < 5)
            {
                arr[index] = new Manager();
                arr[index]->accept();
                arr[index]->display();
                index++;
            }
            else
            {
                cout << "Stack Overflow" << endl;
            }
            break;
        case 2:
            if (index < 5)
            {
                arr[index] = new SalesMan();
                arr[index]->accept();
                arr[index]->display();
                index++;
            }
            else
            {
                cout << "Stack Overflow" << endl;
            }
            break;
        case 3:
            if (index < 5)
            {
                arr[index] = new SalesManager();
                arr[index]->accept();
                arr[index]->display();
                index++;
            }
            else
            {
                cout << "Stack Overflow" << endl;
            }
            break;
        case 4:

        {
            int a = 0, b = 0, c = 0;
            for (int i = 0; i < index; i++)
            {
                if (typeid(*arr[i]).name() == typeid(Manager).name())
                    a++;
                else if (typeid(*arr[i]).name() == typeid(SalesMan).name())
                    b++;
                else
                    c++;
            }
            cout << "MANAGER:---" << a << endl;
            cout << "SalesMan:---" << b << endl;
            cout << "SalesMAnager:---" << c << endl;
        }
        break;
        case 5:
        {
            for (int i = 0; i < index; i++)
            {
                if (typeid(*arr[i]) == typeid(Manager))
                {
                    arr[i]->display();
                }
            }
            break;
        }

        case 6:
        {
            for (int i = 0; i < index; i++)
            {
                if (typeid(*arr[i]) == typeid(SalesMan))
                {
                    arr[i]->display();
                }
            }
            break;
        }

        case 7:
        {
            for (int i = 0; i < index; i++)
            {
                if (typeid(*arr[i]) == typeid(SalesManager))
                {
                    arr[i]->display();
                }
            }
            break;
        }
        }
    }

    return 0;
}
