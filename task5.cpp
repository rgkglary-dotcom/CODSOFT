#include <iostream>
#include <string>
using namespace std;
string bookTitle[100], bookAuthor[100], bookISBN[100], issuedTo[100];
bool isAvailable[100];
int totalBooks = 0;
void addBook() 
{
    cout << "Enter Book Title: ";
    getline(cin, bookTitle[totalBooks]);
    cout << "Enter Author Name: ";
    getline(cin, bookAuthor[totalBooks]);
    cout << "Enter ISBN: ";
    getline(cin, bookISBN[totalBooks]);
    isAvailable[totalBooks] = true;
    issuedTo[totalBooks] = "";
    totalBooks++;
    cout << "Book added successfully.\n";
}
void viewBooks() 
{
    if (totalBooks == 0) 
    {
        cout << "No books available.\n";
        return;
    }
    cout << "\n--- Book List ---\n";
    for (int i = 0; i < totalBooks; i++) {
        cout << "\nBook " << i + 1 << "\n";
        cout << "Title  : " << bookTitle[i] << "\n";
        cout << "Author : " << bookAuthor[i] << "\n";
        cout << "ISBN   : " << bookISBN[i] << "\n";
        if (isAvailable[i])
            cout << "Status : Available\n";
        else
            cout << "Status : Issued to " << issuedTo[i] << "\n";
    }
}
void searchBook() 
{
    string key;
    cout << "Enter Title, Author or ISBN: ";
    getline(cin, key);
    bool found = false;
    for (int i = 0; i < totalBooks; i++) {
        if (bookTitle[i] == key || bookAuthor[i] == key || bookISBN[i] == key) {
            cout << "\nMatch found -\n";
            cout << "Title  : " << bookTitle[i] << "\n";
            cout << "Author : " << bookAuthor[i] << "\n";
            cout << "ISBN   : " << bookISBN[i] << "\n";
            cout << (isAvailable[i] ? "Status : Available\n" : "Status : Issued\n");
            found = true;
        }
    }
    if (!found)
        cout << "No matching book found.\n";
}
void checkoutBook() 
{
    string isbn;
    cout << "Enter ISBN of the book: ";
    getline(cin, isbn);
    for (int i = 0; i < totalBooks; i++) {
        if (bookISBN[i] == isbn) {
            if (!isAvailable[i]) {
                cout << "That book is already issued.\n";
                return;
            }
            cout << "Enter Borrower Name: ";
            getline(cin, issuedTo[i]);
            isAvailable[i] = false;
            cout << "Book checked out.\n";
            return;
        }
    }
    cout << "Book not found.\n";
}

void returnBook() {
    string isbn;
    cout << "Enter ISBN of returned book: ";
    getline(cin, isbn);

    for (int i = 0; i < totalBooks; i++) {
        if (bookISBN[i] == isbn) {
            if (isAvailable[i]) {
                cout << "That book wasn't issued in the first place.\n";
                return;
            }
            isAvailable[i] = true;
            issuedTo[i] = "";
            cout << "Book returned.\n";
            return;
        }
    }
    cout << "Book not found.\n";
}

void fineCalc() {
    int days;
    cout << "Enter overdue days: ";
    cin >> days;
    cin.ignore();

    // flat rate, 5 rs per day late
    double fine = (days > 0) ? days * 5 : 0;
    cout << "Fine Amount = Rs. " << fine << "\n";
}

int main() {
    int choice;

    while (true) {
        cout << "\n===== LIBRARY MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Book\n";
        cout << "2. View Books\n";
        cout << "3. Search Book\n";
        cout << "4. Checkout Book\n";
        cout << "5. Return Book\n";
        cout << "6. Fine Calculation\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: addBook(); break;
            case 2: viewBooks(); break;
            case 3: searchBook(); break;
            case 4: checkoutBook(); break;
            case 5: returnBook(); break;
            case 6: fineCalc(); break;
            case 7:
                cout << "Thanks for using the Library Management System.\n";
                return 0;
            default:
                cout << "Invalid choice, try again.\n";
        }
    }
}