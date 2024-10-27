#include <iostream>
using namespace std;

struct date
{
    /* data */
    int day, month, year;

    void initDate()
    {
        day = 1;
        month = 1;
        year = 1900;
    }

    void printDateOnConsole()
    {
        cout << day << '/' << month << '/' << year << endl;
    }

    void acceptDateFromConsole()
    {
        cout << "Enter day, Month, Year: ";
        cin >> day >> month >> year;
    }

    // bool isLeapYear(){

    // }
};
// using Class
class dateclass
{
private:
    int day, month, year;

public:
    void initDate()
    {
        day = 1;
        month = 1;
        year = 1900;
    }
    void printDateOnConsole()
    {
        cout <<"Date - "<<this-> day << "/" <<this-> month << "/" <<this-> year << endl;
    }
    void acceptDateFromConsole()
    {
        cout << "Enter the Date -: ";
        cin >> day >> month >> year;
    }

    // bool isLeapYear(){

    // }
};

int main()
{

    int choice;
    date date1;
    dateclass date2;
    do
    {
        cout << "Menu ---->"<<endl;
        cout << "Enter 1 to Initialize Date" << endl;
        cout << "Enter 2 to Date Print" << endl;
        cout << "Enter 3 to Accept Date" << endl;



        cout << "Choice Enter -: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            date1.initDate();
            cout << "InitiateDate - " << endl;
            break;
        case 2:
            cout << "PrintDate -: " << endl;
            date1.printDateOnConsole();
            break;
        case 3:
            date1.acceptDateFromConsole();
            cout << "AcceptDate -:" << endl;
            break;
        case 4:
            cout<<"Exit-------->"<<endl;    

        default:
            cout << "Invalid Choice";

            break;
        }
        } while (choice != 5);

        return 0;
    };