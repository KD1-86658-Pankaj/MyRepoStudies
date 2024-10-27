#include <iostream>
#include <string>
using namespace std;

class Product {
protected:
    int id;
    string title;
    double price;

public:
    Product(int id, string title, double price) {
        this->id = id;
        this->title = title;
        this->price = price;
    }

    virtual double getPrice() {
        return price;
    }

    string getTitle() {
        return title;
    }
};

class Book : public Product {
private:
    string author;

public:
    Book(int id, string title, string author, double price) : Product(id, title, price) {
        this->author = author;
    }

    double getPrice() override {
        return price * 0.10; 
    }
};

class Tape : public Product {
private:
    string artist;

public:
    Tape(int id, string title, string artist, double price) : Product(id, title, price) {
        this->artist = artist;
    }

    double getPrice() override {
        return price * 0.95;
    }
};

int main() {
    Product* arr[3];
    int choice;
    double total = 0;

    arr[0] = new Book(1, "Book ", "Author 1", 20.0);
    arr[1] = new Tape(2, "Tape ", "Artist 1", 15.0);
    arr[2] = new Book(3, "Book ", "Author 2", 25.0);

    do {
        cout << "Menu:\n";
        cout << "1. Buy a product\n";
        cout << "2. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                for (int i = 0; i < 3; i++) {
                    cout << i + 1 << ". " << arr[i]->getTitle() << " - $" << arr[i]->getPrice() << endl;
                }
                int selectedIndex;
                cout << "Enter the product number to buy: ";
                cin >> selectedIndex;
                total += arr[selectedIndex - 1]->getPrice();
                cout << "Product added to cart. Total: $" << total << endl;
                break;
            }
            case 2:
                cout << "Final bill: $" << total << endl;
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 2);

    for (int i = 0; i < 3; i++) {
        delete arr[i];
    }

    return 0;
}