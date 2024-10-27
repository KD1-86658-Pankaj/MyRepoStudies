//  Create a namespace NStudent. Create the Student class(created as per Q2) inside namespace. 
// Create the object of student and perform accept and display student.


#include <iostream>
#include <string>
using namespace std;

namespace Nstudent {
    class Student {
    private:
        int rollNo;
        string name;
        int marks;

    public:
        void acceptStudent() {
            cout << "Enter roll number: ";
            cin >> rollNo;
            cout << "Enter name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter marks: ";
            cin >> marks;
        }

        void displayStudent() {
            cout << "Roll Number: " << rollNo << endl;
            cout << "Name: " << name << endl;
            cout << "Marks: " << marks << endl;
        }
    };
}

using namespace Nstudent;

int main() {
    Student s;
    s.acceptStudent();
    cout << "Student details:" << endl;
    s.displayStudent();


    
    return 0;
}