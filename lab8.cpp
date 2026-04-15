#include <iostream>
#include <string>
using namespace std;


struct Book {
    string title;
    string author;
    int year;
    Book* next;
    Book* prev;
};

void addBooks(Book*& head, int n) {
    for (int i = 0; i < n; i++) {
        Book* newBook = new Book;

        cin.ignore();

        cout << "\nBook " << i + 1 << endl;

        cout << "Title: ";
        getline(cin, newBook->title);

        cout << "Author: ";
        getline(cin, newBook->author);

        cout << "Year: ";
        cin >> newBook->year;

        newBook->next = NULL;
        newBook->prev = NULL;

        if (head == NULL) {
            head = newBook;
        } else {
            Book* temp = head;
            while (temp->next != NULL)
                temp = temp->next;

            temp->next = newBook;
            newBook->prev = temp;
        }
    }
}

void printForward(Book* head) {
    cout << "\nForward:\n";
    while (head != NULL) {
        cout << head->title << " | "
             << head->author << " | "
             << head->year << endl;
        head = head->next;
    }
}

void printBackward(Book* head) {
    cout << "\nBackward:\n";

    if (head == NULL) return;

    while (head->next != NULL)
        head = head->next;

    while (head != NULL) {
        cout << head->title << " | "
             << head->author << " | "
             << head->year << endl;
        head = head->prev;
    }
}

void mergeBooks(Book*& A, Book*& B) {
    if (A == NULL) {
        A = B;
        return;
    }

    Book* temp = A;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = B;

    if (B != NULL)
        B->prev = temp;
}

void deleteBooks(Book*& head) {
    while (head != NULL) {
        Book* temp = head;
        head = head->next;
        delete temp;
    }
}


struct Bus {
    int number;
    string destination;
    int passengers;
    Bus* next;
};

void addQueue(Bus*& front, Bus*& rear, int n) {
    for (int i = 0; i < n; i++) {
        Bus* newBus = new Bus;

        cout << "\nBus " << i + 1 << endl;

        cout << "Number: ";
        cin >> newBus->number;

        cin.ignore();

        cout << "Destination: ";
        getline(cin, newBus->destination);

        cout << "Passengers: ";
        cin >> newBus->passengers;

        newBus->next = NULL;

        if (rear == NULL) {
            front = rear = newBus;
        } else {
            rear->next = newBus;
            rear = newBus;
        }
    }
}

void mergeQueue(Bus*& f1, Bus*& r1, Bus*& f2, Bus*& r2) {
    if (f1 == NULL) {
        f1 = f2;
        r1 = r2;
        return;
    }

    r1->next = f2;
    if (r2 != NULL)
        r1 = r2;
}

void printQueue(Bus* front) {
    cout << "\nQueue:\n";
    while (front != NULL) {
        cout << front->number << " | "
             << front->destination << " | "
             << front->passengers << endl;
        front = front->next;
    }
}

void printMore(Bus* front, int k) {
    cout << "\nPassengers > " << k << ":\n";
    while (front != NULL) {
        if (front->passengers > k)
            cout << front->number << " | "
                 << front->destination << " | "
                 << front->passengers << endl;
        front = front->next;
    }
}

void removeTwo(Bus*& front) {
    for (int i = 0; i < 2; i++) {
        if (front == NULL) return;

        Bus* temp = front;
        front = front->next;
        delete temp;
    }
}

void deleteQueue(Bus*& front) {
    while (front != NULL) {
        Bus* temp = front;
        front = front->next;
        delete temp;
    }
}


int main() {
    Book* A = NULL;
    Book* B = NULL;

    Bus* f1 = NULL;
    Bus* r1 = NULL;
    Bus* f2 = NULL;
    Bus* r2 = NULL;

    int choice, n, m, k;

    do {
        cout << "\n===== MAIN MENU =====\n";
        cout << "1. Create book list A (n elements)\n";
        cout << "2. Create book list B (m elements)\n";
        cout << "3. Show both lists (forward & backward)\n";
        cout << "4. Merge book lists\n";
        cout << "5. Create queue 1\n";
        cout << "6. Create queue 2\n";
        cout << "7. Merge queues\n";
        cout << "8. Show queue\n";
        cout << "9. Show buses with passengers > k\n";
        cout << "10. Remove first 2 buses\n";
        cout << "0. Exit\n";
        cout << "Choose: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Enter n: ";
            cin >> n;
            addBooks(A, n);
            break;

        case 2:
            cout << "Enter m: ";
            cin >> m;
            addBooks(B, m);
            break;

        case 3:
            cout << "\nLIST A:";
            printForward(A);
            printBackward(A);

            cout << "\nLIST B:";
            printForward(B);
            printBackward(B);
            break;

        case 4:
            mergeBooks(A, B);
            cout << "\nMerged list:";
            printForward(A);
            break;

        case 5:
            cout << "Enter size: ";
            cin >> n;
            addQueue(f1, r1, n);
            break;

        case 6:
            cout << "Enter size: ";
            cin >> m;
            addQueue(f2, r2, m);
            break;

        case 7:
            mergeQueue(f1, r1, f2, r2);
            cout << "Queues merged\n";
            break;

        case 8:
            printQueue(f1);
            break;

        case 9:
            cout << "Enter k: ";
            cin >> k;
            printMore(f1, k);
            break;

        case 10:
            removeTwo(f1);
            cout << "After removing:";
            printQueue(f1);
            break;

        case 0:
            deleteBooks(A);
            deleteBooks(B);
            deleteQueue(f1);
            deleteQueue(f2);
            cout << "Memory cleared. Exit.\n";
            break;

        default:
            cout << "Wrong choice!\n";
        }

    } while (choice != 0);

    return 0;
}