#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Base class Employee
class Employee
{
protected:
    int id;
    double salary;

public:
    Employee() : id(0), salary(0.0) {}

    Employee(int id, double salary) : id(id), salary(salary) {}

    void setId(int id)
    {
        this->id = id;
    }

    int getId() const
    {
        return id;
    }

    void setSalary(double salary)
    {
        this->salary = salary;
    }

    double getSalary() const
    {
        return salary;
    }

    virtual void accept()
    {
        cout << "Enter Employee ID: ";
        cin >> id;
        cout << "Enter Salary: ";
        cin >> salary;
    }

    virtual void display() const
    {
        cout << "ID: " << id << "\nSalary: $" << salary << endl;
    }

    virtual ~Employee() {}
};

class Manager : public Employee
{
private:
    double bonus;

public:
    Manager() : Employee(), bonus(0.0) {}

    Manager(int id, double salary, double bonus) : Employee(id, salary), bonus(bonus) {}

    void setBonus(double bonus)
    {
        this->bonus = bonus;
    }

    double getBonus() const
    {
        return bonus;
    }

    void accept() override
    {
        Employee::accept();
        cout << "Enter Bonus: ";
        cin >> bonus;
    }

    void display() const override
    {
        Employee::display();
        cout << "Bonus: $" << bonus << endl;
    }
};

class Salesman : public Employee
{
private:
    double commission;

public:
    Salesman() : Employee(), commission(0.0) {}

    Salesman(int id, double salary, double commission) : Employee(id, salary), commission(commission) {}

    void setCommission(double commission)
    {
        this->commission = commission;
    }

    double getCommission() const
    {
        return commission;
    }

    void accept() override
    {
        Employee::accept();
        cout << "Enter Commission: ";
        cin >> commission;
    }

    void display() const override
    {
        Employee::display();
        cout << "Commission: $" << commission << endl;
    }
};

class SalesManager : public Manager
{
private:
    double commission;

public:
    SalesManager() : Manager(), commission(0.0) {}

    SalesManager(int id, double salary, double bonus, double commission)
        : Manager(id, salary, bonus), commission(commission) {}

    void setCommission(double commission)
    {
        this->commission = commission;
    }

    double getCommission() const
    {
        return commission;
    }

    void accept() override
    {
        Manager::accept();
        cout << "Enter Commission: ";
        cin >> commission;
    }

    void display() const override
    {
        Manager::display();
        cout << "Commission: $" << commission << endl;
    }
};

int main()
{
    vector<Employee *> employees;
    int choice;

    do
    {
        cout << "\n--- Employee Management System ---\n";
        cout << "1. Accept Employee\n";
        cout << "   a. Accept Manager\n";
        cout << "   b. Accept Salesman\n";
        cout << "   c. Accept SalesManager\n";
        cout << "2. Display Count of Employees by Designation\n";
        cout << "3. Display All Managers\n";
        cout << "4. Display All Salesmen\n";
        cout << "5. Display All SalesManagers\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cout << "   a. Accept Manager (1)\n";
            cout << "   b. Accept Salesman (2)\n";
            cout << "   c. Accept SalesManager (3)\n";
            int type;
            cout << "Enter your choice: ";
            cin >> type;

            if (type == 1)
            {
                Manager *m = new Manager();
                m->accept();
                employees.push_back(m);
            }
            else if (type == 2)
            {
                Salesman *s = new Salesman();
                s->accept();
                employees.push_back(s);
            }
            else if (type == 3)
            {
                SalesManager *sm = new SalesManager();
                sm->accept();
                employees.push_back(sm);
            }
            else
            {
                cout << "Invalid option.\n";
            }
            break;
        }

        case 2:
        {
            int managerCount = 0, salesmanCount = 0, salesManagerCount = 0;

            for (const auto &emp : employees)
            {
                if (dynamic_cast<Manager *>(emp) && !dynamic_cast<SalesManager *>(emp))
                {
                    managerCount++;
                }
                else if (dynamic_cast<Salesman *>(emp) && !dynamic_cast<SalesManager *>(emp))
                {
                    salesmanCount++;
                }
                else if (dynamic_cast<SalesManager *>(emp))
                {
                    salesManagerCount++;
                }
            }

            cout << "Total Managers: " << managerCount << endl;
            cout << "Total Salesmen: " << salesmanCount << endl;
            cout << "Total SalesManagers: " << salesManagerCount << endl;
            break;
        }

        case 3:
        {
            cout << "--- List of All Managers ---\n";
            for (const auto &emp : employees)
            {
                if (dynamic_cast<Manager *>(emp) && !dynamic_cast<SalesManager *>(emp))
                {
                    emp->display();
                    cout << endl;
                }
            }
            break;
        }

        case 4:
        {
            cout << "--- List of All Salesmen ---\n";
            for (const auto &emp : employees)
            {
                if (dynamic_cast<Salesman *>(emp) && !dynamic_cast<SalesManager *>(emp))
                {
                    emp->display();
                    cout << endl;
                }
            }
            break;
        }

        case 5:
        {
            cout << "--- List of All SalesManagers ---\n";
            for (const auto &emp : employees)
            {
                if (dynamic_cast<SalesManager *>(emp))
                {
                    emp->display();
                    cout << endl;
                }
            }
            break;
        }

        case 6:
        {
            cout << "Exiting...\n";
            break;
        }

        default:
            cout << "Invalid option.\n";
            break;
        }
    } while (choice != 6);

    for (auto &emp : employees)
    {
        delete emp;
    }
    employees.clear();

    return 0;
}
