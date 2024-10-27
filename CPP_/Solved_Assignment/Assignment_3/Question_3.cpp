#include <iostream>
using namespace std;

class Address
{

    string building;
    string street;
    string city;
    int pin;

public:
    Address()
    {
        building = "Tower_11";
        street = "Gandhi Road";
        city = "Pune";
        pin = 453534;
    }

    void setBuilding()
    {
        cout << "Enter the Building Name -: " << endl;
        cin >> building;
    }
    void setStreet()
    {
        cout << "Enter The Street Name -: " << endl;
        cin >> street;
    }

    void setCity()
    {
        cout << "Enter the City Name -: " << endl;
        cin >> city;
    }

    void setPin()
    {
        cout << "Enter the Pin -: " << endl;
        cin >> pin;
    }

    void getBuilding()
    {
        cout << "Enter the Building Name -: " << endl;
        cin >> building;
    }
    void getStreet()
    {
        cout << "Enter the Street Name -: " << endl;
        cin >> street;
    }

    void getCity()
    {
        cout << "Enter the City Name -: " << endl;
        cin >> city;
    }

    void getPin()
    {
        cout << "Enter the Pin -: " << endl;
        cin >> pin;
    }

    void accept()
    {
        cout << "Enter the Building Name -: " << endl;
        cin >> building;

        cout << "Enter the Street Name -:" << endl;
        cin >> street;

        cout << "Enter the City Name -: " << endl;
        cin >> city;

        cout << "Enter the Pin -: " << endl;
        cin >> pin;
    }
    void display()
    {
        cout << "Building Name -: " << building << "  " << "Street Name - " << street << "  " << "City Name -: " << city << "  " << "Pincode - " << pin << "  " << endl;
    }
};

int main()
{

    Address A1;
    int choice;
    do
    {
        cout << "Enter 1 to Set Building Name " << endl;
        cout << " Enter 2 to Set Street Name  " << endl;
        cout << " Enter 3 to Set City Name  " << endl;
        cout << " Enter 4 to Set Pin Number  " << endl;
        cout << " Enter 5 to Set Accept All Values  " << endl;
        cout << " Enter 6 to Get Building Name  " << endl;
        cout << " Enter 7 to Get Street Name  " << endl;
        cout << " Enter 8 to Get City Name  " << endl;
        cout << " Enter 9 to Get Pin Number  " << endl;
        cout << " Enter 10 to Get All Address  " << endl;

        cout << "Enter Choice -: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            A1.setBuilding();
            break;
        case 2:
            A1.setStreet();
            break;
        case 3:
            A1.setCity();
            break;
        case 4:
            A1.setPin();
            break;
        case 5:
            A1.accept();
            break;
        case 6:
            A1.getBuilding();
            break;
        case 7:
            A1.getStreet();
            break;
        case 8:
            A1.getCity();
            break;
        case 9:
            A1.getPin();
            break;
        case 10:
            A1.display();
            break;

        default:
            cout << "Invalid.......Error";
            break;
        }

    } while (choice != 10);

        return 0;
}