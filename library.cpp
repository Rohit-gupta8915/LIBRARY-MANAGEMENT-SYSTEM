#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Book Class
class Book {
public:
    int bookID;
    string title;
    string author;
    bool issued;

    Book(int id, string t, string a) {
        bookID = id;
        title = t;
        author = a;
        issued = false;
    }
};

// Member Class
class Member {
public:
    int memberID;
    string name;

    Member(int id, string n) {
        memberID = id;
        name = n;
    }
};

// Library Class
class Library {
private:
    vector<Book> books;
    vector<Member> members;

public:

    // Add a book
    void addBook() {
        int id;
        string title, author;

        cout << "\nEnter Book ID: ";
        cin >> id;
        cin.ignore();

        cout << "Enter Book Title: ";
        getline(cin, title);

        cout << "Enter Author Name: ";
        getline(cin, author);

        books.push_back(Book(id, title, author));

        cout << "Book added successfully!\n";
    }

    // Add a member
    void addMember() {
        int id;
        string name;

        cout << "\nEnter Member ID: ";
        cin >> id;
        cin.ignore();

        cout << "Enter Member Name: ";
        getline(cin, name);

        members.push_back(Member(id, name));

        cout << "Member added successfully!\n";
    }

    // Display all books
    void displayBooks() {
        if (books.empty()) {
            cout << "\nNo books available.\n";
            return;
        }

        cout << "\n----- BOOK LIST -----\n";

        for (const auto &book : books) {
            cout << "Book ID: " << book.bookID << endl;
            cout << "Title: " << book.title << endl;
            cout << "Author: " << book.author << endl;
            cout << "Status: "
                 << (book.issued ? "Issued" : "Available") << endl;
            cout << "--------------------\n";
        }
    }

    // Issue a book
    void issueBook() {
        int bookID, memberID;

        cout << "\nEnter Book ID: ";
        cin >> bookID;

        cout << "Enter Member ID: ";
        cin >> memberID;

        bool bookFound = false;
        bool memberFound = false;

        for (const auto &member : members) {
            if (member.memberID == memberID) {
                memberFound = true;
                break;
            }
        }

        if (!memberFound) {
            cout << "Member not found!\n";
            return;
        }

        for (auto &book : books) {
            if (book.bookID == bookID) {
                bookFound = true;

                if (book.issued) {
                    cout << "Book is already issued!\n";
                } else {
                    book.issued = true;
                    cout << "Book issued successfully!\n";
                }

                break;
            }
        }

        if (!bookFound) {
            cout << "Book not found!\n";
        }
    }

    // Return a book
    void returnBook() {
        int bookID;

        cout << "\nEnter Book ID: ";
        cin >> bookID;

        for (auto &book : books) {
            if (book.bookID == bookID) {

                if (book.issued) {
                    book.issued = false;
                    cout << "Book returned successfully!\n";
                } else {
                    cout << "This book was not issued.\n";
                }

                return;
            }
        }

        cout << "Book not found!\n";
    }

    // Search book by title
    void searchByTitle() {
        string title;

        cin.ignore();
        cout << "\nEnter title to search: ";
        getline(cin, title);

        bool found = false;

        for (const auto &book : books) {
            if (book.title.find(title) != string::npos) {
                cout << "\nBook Found!\n";
                cout << "Book ID: " << book.bookID << endl;
                cout << "Title: " << book.title << endl;
                cout << "Author: " << book.author << endl;
                cout << "Status: "
                     << (book.issued ? "Issued" : "Available") << endl;

                found = true;
            }
        }

        if (!found) {
            cout << "No book found with this title.\n";
        }
    }

    // Search book by author
    void searchByAuthor() {
        string author;

        cin.ignore();
        cout << "\nEnter author name to search: ";
        getline(cin, author);

        bool found = false;

        for (const auto &book : books) {
            if (book.author.find(author) != string::npos) {
                cout << "\nBook Found!\n";
                cout << "Book ID: " << book.bookID << endl;
                cout << "Title: " << book.title << endl;
                cout << "Author: " << book.author << endl;
                cout << "Status: "
                     << (book.issued ? "Issued" : "Available") << endl;

                found = true;
            }
        }

        if (!found) {
            cout << "No book found by this author.\n";
        }
    }
};

// Main Function
int main() {

    Library library;
    int choice;

    do {
        cout << "\n================================\n";
        cout << "     LIBRARY MANAGEMENT SYSTEM\n";
        cout << "================================\n";
        cout << "1. Add Book\n";
        cout << "2. Add Member\n";
        cout << "3. Display All Books\n";
        cout << "4. Issue Book\n";
        cout << "5. Return Book\n";
        cout << "6. Search Book by Title\n";
        cout << "7. Search Book by Author\n";
        cout << "8. Exit\n";
        cout << "================================\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            library.addBook();
            break;

        case 2:
            library.addMember();
            break;

        case 3:
            library.displayBooks();
            break;

        case 4:
            library.issueBook();
            break;

        case 5:
            library.returnBook();
            break;

        case 6:
            library.searchByTitle();
            break;

        case 7:
            library.searchByAuthor();
            break;

        case 8:
            cout << "\nThank you for using Library Management System!\n";
            break;

        default:
            cout << "\nInvalid choice! Try again.\n";
        }

    } while (choice != 8);

    return 0;
}