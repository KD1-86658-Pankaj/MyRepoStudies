#include <iostream>
using namespace std;

class Stack
{
    int *arr;
    int top;
    int capacity;

public:
    Stack()
    {
        arr = new int[5];
        top = -1;
        capacity = 5;
    }
    Stack(int capacity)
    {

        arr = new int[capacity];
        top = -1;
        this->capacity = capacity;
    }
    ~Stack()
    {
        delete[] arr;
    }
    bool Isfull()
    {
        if (top == (capacity - 1))
            return true;
        else
            return false;
    }
    bool Isempty()
    {
        if (top == -1)
            return true;
        else
            return false;
    }

    void push(int value)
    {
        if (Isfull())
        {
            cout << "\nStack is full";
            return;
        }
        top++;
        arr[top] = value;
        cout << "Element " << value << " is added to the Stack " << endl;
    }

    void pop()
    {
        if (Isempty())
        {
            cout << "\nStack is Empty";
            return;
        }

        cout << arr[top] << " Removed from the stack" << endl;
        top--;
    }
    void peek()
    {
        if (Isempty())
        {
            cout << "\nStack is Empty";
            return;
        }
        cout << "\nPeek Element :" << arr[top];
    }
    void Display()
    {
        if (Isempty())
        {
            cout << "\nStack is Empty";
            return;
        }
        else
        {
            for (int i = 0; i <= top; i++)
            {
                cout << arr[i] << " ";
            }
        }
    }
};

int main()
{

    int choice;
    Stack *ptr = new Stack();

    do
    {
        cout << "\nMenu:" << endl;
        cout << "1.Create the Stack" << endl;
        cout << "2.Insert element in the Stack" << endl;
        cout << "3.Pop the element from the stack " << endl;
        cout << "4.Peek element of the stack " << endl;
        cout << "5.Display the elements from the Stack " << endl;
        cout << "6.Exit " << endl;

        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int choice2;
            delete ptr; // Free the old stack
            cout << "1.Create the Stack with deault size" << endl;
            cout << "2.Create the Stack with input size" << endl;
            cin >> choice2;
            if (choice2 == 1)
                ptr = new Stack();
            else
            {

                int capacity;
                cout << "Enter the Size of the stack:";
                cin >> capacity;
                ptr = new Stack(capacity);
            }
        }
        break;
        case 2:
        {
            int element;
            cout << "Enter the element you want to enter into the stack: ";
            cin >> element;
            ptr->push(element);
        }
        break;
        case 3:
        {
            ptr->pop();
        }
        break;
        case 4:
        {
            ptr->peek();
        }
        break;
        case 5:
        {
            ptr->Display();
        }
        break;
        case 6:
        {
            cout << "Exiting program........";
        }
        break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);
}