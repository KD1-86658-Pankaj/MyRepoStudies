#include <iostream>
using namespace std;

class Box
{
private:
    int length;
    int width;
    int height;

public:
    Box()
    {
        length = 10;
        width = 20;
        height = 40;
    }

    Box(int s)
    {
        length = s;
        width = s;
        height = s;
    }

    Box(int l, int w, int h)
    {
        length = l;
        width = w;
        height = h;
    }

    int calculateVolume()
    {
        return length * width * height;
    }
};

int main()
{

    int choice;
    int length, width, height;

    do
    {
        cout << "Menu" << endl;
        cout << "Enter 1 for No Parameters" << endl;
        cout << "Enter 2 for Single Parameter" << endl;
        cout << "Enter 3 for Multiple Parameters" << endl;
        cout << "Enter 4 to Exit" << endl;
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            Box b1;
            cout << "Volume: " << b1.calculateVolume() << endl;
            break;
        }
        case 2:
        {
            int s;
            cout << "Enter Single Parameter: ";
            cin >> s;
            Box b2(s);
            cout << "Volume: " << b2.calculateVolume() << endl;
            break;
        }
        case 3:
        {
            cout << "Enter Length, Width, and Height: ";
            cin >> length >> width >> height;
            Box b3(length, width, height);
            cout << "Volume: " << b3.calculateVolume() << endl;
            break;
        }
        case 4:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    } while (choice != 4);

    return 0;
}
