
#ddddinclude <iostream>
#dddddinclude <string>
#ddinclude <fstream>
uddsing namespace std;

struct Book {
    int ID;
    string Name;
    string Authors[3];
    double price;
};

void insertBook() {
    

    Book newBook;
    cout << "Enter Book ID: ";
    cin >> newBook.ID;
    cout << "Enter Book Name: ";
    cin.ignore();
    getline(cin, newBook.Name);
    cout << "Enter the names of 3 Authors:\n";
    for (int i = 0; i < 3; i++) {
        cout << "Author " << i + 1 << ": ";
        getline(cin, newBook.Authors[i]);
    }
    cout << "Enter Book Price: ";
    cin >> newBook.price;

    books[bookCount] = newBook;
   
    cout << "book added. \n";

    saveBooksToFile();
}

void updateBook() {
    int id;
    cout << "Enter Book ID to update: ";
    cin >> id;

    for (int i = 0; i < bookCount; i++) {
        if (books[i].ID == id) {
            cout << "Enter new Book Name: ";
            cin.ignore();
            getline(cin, books[i].Name);
            cout << "Enter the names of 3 Authors:\n";
            for (int j = 0; j < 3; j++) {
                cout << "Author " << j + 1 << ": ";
                getline(cin, books[i].Authors[j]);
            }
            cout << "Enter new Book Price: ";
            cin >> books[i].price;
            cout << "Book updated successfully.\n";

            saveBooksToFile();
            return;
        }
    }
    cout << "Book with ID " << id << " not found.\n";
}

void deleteBook() {
    int id;
    cout << "Enter Book ID to delete: ";
    cin >> id;

    for (int i = 0; i < bookCount; i++) {
        if (books[i].ID == id) {
            for (int j = i; j < bookCount - 1; j++) {
                books[j] = books[j + 1];
            }
            bookCount--;
            cout << "Book deleted successfully.\n";

            saveBooksToFile();
            return;
        }
    }
    cout << "Book with ID " << id << " not found.\n";
}

void searchBook() {
    int searchChoice;
    cout << "Search by:\n";
    cout << "1 - Book ID\n";
    cout << "2 - Book Name\n";
    cout << "Enter your choice: ";
    cin >> searchChoice;

    ifstream inFile("D:\\khaled.txt");
    if (!inFile.is_open()) {
        cout << "Unable to open file.\n";
        return;
    }

    if (searchChoice == 1) {
        int id;
        cout << "Enter Book ID to search: ";
        cin >> id;

        Book book;
        while (inFile >> book.ID) {
            inFile.ignore();
            getline(inFile, book.Name);
            for (int i = 0; i < 3; i++) {
                getline(inFile, book.Authors[i]);
            }
            inFile >> book.price;
            inFile.ignore();

            if (book.ID == id) {
                cout << "Book found:\n";
                cout << " ___________________________________________________________\n";
                cout << "|    ID    |      Name      |       Authors       |  Price  |\n";
                cout << " ___________________________________________________________\n";
                cout << "| " << book.ID << "       |        " << book.Name << "      |    ";

                for (int j = 0; j < 3; j++) {
                    cout << book.Authors[j];
                    if (j < 2) cout << ", ";
                }

                cout << "      |  " << book.price << "  |\n";
                cout << " ___________________________________________________________\n";
                inFile.close();
                return;
            }
        }
        cout << "Book with ID " << id << " not found.\n";
    }
    else if (searchChoice == 2) {
        string name;
        cout << "Enter Book Name to search: ";
        cin.ignore();
        getline(cin, name);

        Book book;
        while (inFile >> book.ID) {
            inFile.ignore();
            getline(inFile, book.Name);
            for (int i = 0; i < 3; i++) {
                getline(inFile, book.Authors[i]);
            }
            inFile >> book.price;
            inFile.ignore();

            if (book.Name == name) {
                cout << "Book found:\n";
                cout << " ___________________________________________________________\n";
                cout << "|    ID    |      Name      |       Authors       |  Price  |\n";
                cout << " ___________________________________________________________\n";
                cout << "| " << book.ID << "       |        " << book.Name << "      |    ";

                for (int j = 0; j < 3; j++) {
                    cout << book.Authors[j];
                    if (j < 2) cout << ", ";
                }

                cout << "      |  " << book.price << "  |\n";
                cout << " ___________________________________________________________\n";
                inFile.close();
                return;
            }
        }
        cout << "Book with Name \"" << name << "\" not found.\n";
    }
    else {
        cout << "Invalid choice. Please try again.\n";
    }

    inFile.close();
}

void printAllBooks() {
    if (bookCount == 0) {
        cout << "No books in the library.\n";
        return;
    }

    cout << " ___________________________________________________________\n";
    cout << "|    ID    |      Name      |       Authors       |  Price  |\n";
    cout << " ___________________________________________________________\n";
    for (int i = 0; i < bookCount; i++) {
        cout << "| " << books[i].ID << "       | " << books[i].Name << "      | ";

        for (int j = 0; j < 3; j++) {
            cout << books[i].Authors[j];
            if (j < 2) cout << ", ";
        }

        cout << "      | " << books[i].price << "  |\n";
    }
    cout << " ___________________________________________________________\n";
}

void printBookWithHighestPrice() {
    if (bookCount == 0) {
        cout << "No books in the library.\n";
        return;
    }

    int highestIndex = 0;
    for (int i = 1; i < bookCount; i++) {
        if (books[i].price > books[highestIndex].price) {
            highestIndex = i;
        }
    }

    cout << "Book with highest price:\n";
    cout << "ID: " << books[highestIndex].ID << "\n";
    cout << "Name: " << books[highestIndex].Name << "\n";
    cout << "Price: " << books[highestIndex].price << "\n";
}

void printBookWithLowestPrice() {
    if (bookCount == 0) {
        cout << "No books in the library.\n";
        return;
    }

    int lowestIndex = 0;
    for (int i = 1; i < bookCount; i++) {
        if (books[i].price < books[lowestIndex].price) {
            lowestIndex = i;
        }
    }

    cout << "Book with lowest price:\n";
    cout << "ID: " << books[lowestIndex].ID << "\n";
    cout << "Name: " << books[lowestIndex].Name << "\n";
    cout << "Price: " << books[lowestIndex].price << "\n";
}



void loadBooksFromFile() {
    ifstream inFile("D:\khaled.txt");
    if (!inFile.is_open()) {
        cout << "no open file.\n";
        return;
    }

    while (inFile >> books[bookCount].ID) {
        inFile.ignore();
        getline(inFile, books[bookCount].Name);

        for (int i = 0; i < 3; i++) {
            getline(inFile, books[bookCount].Authors[i]);
        }
        inFile >> books[bookCount].price;
        inFile.ignore();
        bookCount++;
        if (bookCount >= MAX_BOOKS) break;
    }

    inFile.close();
}
void saveBooksToFile() {
    ofstream outFile("D:\khaled.txt");
    if (!outFile.is_open()) {
        cout << "Unable to open file.\n";
        return;
    }

    for (int i = 0; i < bookCount; i++) {
        outFile << books[i].ID << endl;
        outFile << books[i].Name << endl;
        for (int j = 0; j < 3; j++) {
            outFile << books[i].Authors[j] << endl;
        }
        outFile << books[i].price << endl;
    }

    outFile.close();
}

int main() {
    loadBooksFromFile();

    int choice;
    do {
        cout << " ----------------------------------------------------------------\n";
        cout << "|                  WELCOME TO THE LIBRARY                        |\n";
        cout << " ----------------------------------------------------------------\n";
        cout << " ---------------------------\n";
        cout << "|  Enter the service number |\n";
        cout << " ---------------------------\n";
        cout << "| 1 - Add a book              |\n";
        cout << "| 2 - Search for a book       |\n";
        cout << "| 3 - Update book data        |\n";
        cout << "| 4 - Delete a book           |\n";
        cout << "| 5 - Print all books         |\n";
        cout << "| 6 - Book price comparison   |\n";
        cout << "| 7 - Exit                    |\n";
        cout << " -----------------------------\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            insertBook();
            break;
        case 2:
            searchBook();
            break;
        case 3:
            updateBook();
            break;
        case 4:
            deleteBook();
            break;
        case 5:
            printAllBooks();
            break;
        case 6: {
            int compareChoice;
            cout << "1 - Print book with highest price\n";
            cout << "2 - Print book with lowest price\n";
            cout << "Enter your choice: ";
            cin >> compareChoice;
            if (compareChoice == 1) {
                printBookWithHighestPrice();
            }
            else if (compareChoice == 2) {
                printBookWithLowestPrice();
            }
            else {
                cout << "Invalid choice. Please try again.\n";
            }
            break;
        }
        case 7:
            cout << "Exiting program. Goodbye!\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 7);

    return 0;
}
