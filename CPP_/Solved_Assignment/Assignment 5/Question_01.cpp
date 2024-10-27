#include <iostream>
using namespace std;

class Date
{
    int day;
    int month;
    int year;

public:
    Date()
    {
        day = 1;
        month = 1;
        year = 2000;
    }

    Date(int a, int b, int c)
    {
        day = a;
        month = b;
        year = c;
    }

    void displayDate()
    {
        cout << day << "/" << month << "/" << year << endl;
    }
};

class person
{
public:
    string name;
    string address;
    Date birthdate;

    person()
    {
        name = "";
        address = "";
        birthdate = Date();
    }

    person(string n, string adr, Date d) : birthdate(d)
    {
        name = n;
        address = adr;
    }

    void DisplayPerson()
    {
        cout << "Name -: " << name << endl;
        cout << "Address -: " << address << endl;
        cout << "Birthdate -: ";
        birthdate.displayDate();
    }
};

int main()
{
    Date birthdate1(15, 8, 1995);
    person person1("Anil", "Pune, Maharashtra", birthdate1);

    cout << "Person Details: " << endl;
    person1.DisplayPerson();

    Date birthdate2(10, 06, 2001);
    person person2("Pankaj", "Wani, Maharashtra", birthdate2);

    cout << "\nAnother Person Details: " << endl;
    person2.DisplayPerson();
    ;

    return 0;
}