#include <iostream>
using namespace std;
class student
{
public:
    string name;
    string Gender;
    int rollno;
    int marks[3];

    student()
    {
        rollno = ++rollno;
    }

    void acceptStudent()
    {
        cout << "Enter Name -: " << endl;
        cin >> name;
        cout << "Enter Gender -: " << endl;
        cin >> Gender;
        cout << "Enter Marks of Three -: " << endl;
        for (int i = 0; i < 3; i++)
        {
            cin >> marks[i];
        }
    }

    float CalculatePercentage()
    {
        int total = 0;
        for (int i = 0; i < 3; i++)
        {
            total += marks[i];
        }
        return total / 3.0;
    }

    void printStudent()
    {
        cout << "Name -: " << name << endl;
        cout << "Rollno -:" << rollno << endl;
        cout << "Gender -: " << Gender << endl;
        cout << "Percetage -: " << CalculatePercentage() << "%" << endl;
    }
};

int main()
{
    student p;
    student *arr[5] = {nullptr};
    int choice;
    int count = 0;

    do
    {
        cout << "Menu...................." << endl;
        cout << "Enter 1 to Accept -: " << endl;
        cout << "Enter 2 to Print -: " << endl;
        cout << "Enter 3 to Search -: " << endl;
        cout << "Enter 4 to Exit -: " << endl;
        cout << "Enter Choice -: " << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            if (count < 5)
            {
                arr[count] = new student();
                arr[count]->acceptStudent();
                count++;
            }
            else
            {
                cout << "Student Reached";
            }
            break;

        case 2:
            for (int i = 0; i < count; i++)
            {
                cout << "Student" << i + 1 << "Details" << endl;
                arr[i]->printStudent();
            }
            break;
            // case 3:
            // cout<<"Search With Rollno -: "<<endl;
            // cin>>rollno;
            // in
        case 0:
            cout << "Exiting Program." << endl;
            break;

        default:
            cout << "Invalid Choice!" << endl;
            break;
        }
    } while (choice != 0);

    return 0;
}