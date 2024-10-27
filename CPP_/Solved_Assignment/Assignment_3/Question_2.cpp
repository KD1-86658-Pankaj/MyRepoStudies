#include <iostream>
using namespace std;

class tollbooth
{

    int totalnumberofcars;
    int totalamtofmoney;
    int totalNonPayingCar;

public:
    tollbooth()
    {
        totalnumberofcars = 0;
        totalamtofmoney = 0;
        totalNonPayingCar = 0;
    }

    void payingcars()
    {
        totalnumberofcars += 1;
        totalamtofmoney += 0.5;
    }

    void nonpayingcars()
    {
        totalNonPayingCar += 1;
        totalnumberofcars = totalnumberofcars + totalNonPayingCar;
    }

    void printonconsole()
    {

        cout << "Total Number of Cars -: " << totalnumberofcars << endl;
        cout << "Total Number of Non-Paying Cars" << totalNonPayingCar << endl;
        cout << "Total Amount -: " << totalamtofmoney << endl;
    }
};

int main()
{

    tollbooth T1;
    int choose;

    do
    {

        cout << "Enter 1 to Paying Cars" << endl;
        cout << "Enter 2 to Non Paying Cars" << endl;
        cout << "Enter 3 to Total Cars and Total Amount " << endl;
        cout << "Enter 4 to Exit........" << endl;
        cout << "Choose -: ";
        cin >> choose;

        switch (choose)
        {
        case 1:
            T1.payingcars();
            break;
        case 2:
            T1.nonpayingcars();
            break;
        case 3:
            T1.printonconsole();
            break;
        default:
            cout << "Exit..........Invalid.....Choice" << endl;
            break;
        }
    } while (choose != 4);

    return 0;
}