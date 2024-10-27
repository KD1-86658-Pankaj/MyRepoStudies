#include <iostream>
using namespace std;
class student
{
    int rollno;
    string name;
    int marks;

public:
    student()
    {
        initStudent();
    }

    void initStudent()
    {
        rollno = 0;
        name = " ";
        marks = 0;
    }

    void printStudentOnConsole()
    {
        cout << "Enter Roll no -: ";
        cin >> rollno;
        cout << "Enter Name -: ";
        cin >> name;
        cout << "Enter Marks -: ";
        cin >> marks;
    }

    void acceptStudentFromConsole()
    {

        cout << "Roll no -:" << rollno << endl;
        cout << "Name -: " << name << endl;
        cout << "Marks -:" << marks<<endl;
    }
};

int main()
{

    student stu;
    int choose;
    do
    {
        cout << "Menu" << endl;
        cout << "Enter 1 to InitStudent info" << endl;
        cout << "Enter 2 Accept Student Info" << endl;
        cout << "Enter 3 to Print Student info" << endl;
        cout << "Enter 4 to Exit" << endl;
        cout << "Choose -: ";
        cin >> choose;

        switch (choose)
        {
        case 1:
            stu.initStudent();
            break;
        case 2:
            cout << "";
            stu.acceptStudentFromConsole();
            break;
        case 3:
            cout << "Student Details:" << endl;
            stu.printStudentOnConsole();
            break;
        case 4:
            cout << "Exit.....";
        default:
            cout << "Invalid choice! Please try again.\n";
        }
    } while (choose != 4);

    return 0;
}