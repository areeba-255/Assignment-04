#include <iostream>
#include <string>
using namespace std;

// Base Class: Item
class Lib {
protected:
    int itemID;
    char title[100];
    bool availability;

public:
    Lib() : itemID(0), availability(true) {
        title[0];
    }

    virtual void inputDetails() = 0;
    virtual void getItemDetails() const = 0;
    virtual bool checkAvailability() const = 0;
    virtual void checkOut() = 0;
    virtual void checkIn() = 0;
};

// Derived Class: Book
class Book : public Lib {
    char author[100];
    char ISBN[20];

public:
    Book() : Lib() {
        author[0];
        ISBN[0];
    }

    void inputDetails() {
        cout << "Enter Book ID: ";
        cin >> itemID;
        cout << "Enter Book Title: ";
        cin >> title;
        cout << "Enter Author: ";
        cin >> author;
        cout << "Enter ISBN: ";
        cin >> ISBN;
    }

    void getItemDetails() const {
        cout << "Book ID: " << itemID << ", Title: " << title << ", Author: " << author << ", ISBN: " << ISBN << ", Available: " << (availability ? "Yes" : "No") << "\n";
    }

    bool checkAvailability() const {
        return availability;
    }

    void checkOut() {
        availability = false;
    }

    void checkIn() {
        availability = true;
    }
};

// Derived Class: Journal
class Journal : public Lib {
    char publisher[100];
    int issueNumber;

public:
    Journal() : Lib(), issueNumber(0) {
        publisher[0];
    }

    void inputDetails() {
        cout << "Enter Journal ID: ";
        cin >> itemID;
        cout << "Enter Journal Title: ";
        cin >> title;
        cout << "Enter Publisher: ";
        cin >> publisher;
        cout << "Enter Issue Number: ";
        cin >> issueNumber;
    }

    void getItemDetails() const {
        cout << "Journal ID: " << itemID << ", Title: " << title << ", Publisher: " << publisher << ", Issue: " << issueNumber << ", Available: ";
        if (availability) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
    bool checkAvailability() const {
        return availability;
    }

    void checkOut() {
        availability = false;
    }

    void checkIn() {
        availability = true;
    }
};

// Class: Member
class Member {
    int memberID;
    char name[100];
    char contactInformation[100];
    int loanLimit;

public:
    Member() : memberID(0), loanLimit(0) {
        name[0];
        contactInformation[0];
    }

    void inputDetails() {
        cout << "Enter Member ID: ";
        cin >> memberID;
        cout << "Enter Member Name: ";
        cin>>name;
        cout << "Enter Contact Information: ";
        cin>>contactInformation;
        cout << "Enter Loan Limit: ";
        cin >> loanLimit;
    }

    void borrowItem(Lib* item) {
        if (item->checkAvailability()) {
            item->checkOut();
            cout << "Book borrowed successfully." << endl;
        }
        else {
            cout << "Book is not available." << endl;
        }
    }

    void returnItem(Lib* item) {
        item->checkIn();
        cout << "Item returned successfully." << endl;
    }
};

// Main Function
int main() {
    int choice;
    Book b1;
    Journal j1;
    Member m1;

    do {
        cout << "Library Management System:" << endl;
        cout << "1. Enter Book Details" << endl;
        cout << "2. Input Journal Details" << endl;
        cout << "3. Input Member Details" << endl;
        cout << "4. View Book" << endl;
        cout << "5. View Journal" << endl;
        cout << "6. Borrow Book" << endl;
        cout << "7. Return Book" << endl;
        cout << "8. Press 8 for Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            b1.inputDetails();
            break;
        case 2:
            j1.inputDetails();
            break;
        case 3:
            m1.inputDetails();
            break;
        case 4:
            b1.getItemDetails();
            break;
        case 5:
            j1.getItemDetails();
            break;
        case 6:
            m1.borrowItem(&b1);  // Borrowing the book (can be modified for other items)
            break;
        case 7:
            m1.returnItem(&b1);  // Returning the book (can be modified for other items)
            break;
        case 8:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 8);

    return 0;
}