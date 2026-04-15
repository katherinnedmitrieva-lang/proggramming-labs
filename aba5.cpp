#include <iostream>
using namespace std;

struct Node1 {
    int data;
    Node1* next;
};

void task1() {
    Node1* head = NULL;

    Node1* n1 = new Node1{1, head};
    head = n1;

    Node1* n2 = new Node1{2, NULL};
    head->next = n2;

    Node1* n3 = new Node1{3, head->next};
    head->next = n3;

    Node1* n4 = new Node1{4, NULL};
    n2->next = n4;

    cout << "List:\n";
    Node1* temp = head;
    int sum = 0, count = 0;

    while (temp) {
        cout << temp->data << " ";
        sum += temp->data;
        count++;
        temp = temp->next;
    }

    cout << "\nAverage: " << (double)sum / count << endl;

    Node1* cur = head;
    Node1* prev = NULL;

    while (cur) {
        if (cur->data % 2 == 0) {
            if (prev == NULL)
                head = cur->next;
            else
                prev->next = cur->next;

            delete cur;
            break;
        }
        prev = cur;
        cur = cur->next;
    }

    cout << "After deletion:\n";
    temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    
    while (head) {
        Node1* t = head;
        head = head->next;
        delete t;
    }
}

struct Node2 {
    string city;
    int dist;
    Node2* next;
};

void task2() {
    Node2* head = NULL;
    int n;

    cout << "Number of cities: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        Node2* node = new Node2;
        cout << "Enter city and distance: ";
        cin >> node->city >> node->dist;
        node->next = head;
        head = node;
    }

    int max1 = -1, max2 = -1;
    string c1, c2;

    Node2* temp = head;
    while (temp) {
        if (temp->dist > max1) {
            max2 = max1;
            c2 = c1;
            max1 = temp->dist;
            c1 = temp->city;
        } else if (temp->dist > max2) {
            max2 = temp->dist;
            c2 = temp->city;
        }
        temp = temp->next;
    }

    cout << "Farthest cities: " << c1 << " and " << c2 << endl;

    Node2* newCity = new Node2{"Paris", 2500, head};
    head = newCity;

    cout << "List after adding:\n";
    temp = head;
    while (temp) {
        cout << temp->city << " " << temp->dist << endl;
        temp = temp->next;
    }

    while (head) {
        Node2* t = head;
        head = head->next;
        delete t;
    }
}

struct Node3 {
    string name;
    int year;
    double price;
    Node3* next;
};

void task3() {
    Node3* head = NULL;
    int n;

    cout << "Number of cars: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        Node3* node = new Node3;
        cout << "Enter name, year, price: ";
        cin >> node->name >> node->year >> node->price;
        node->next = head;
        head = node;
    }

    int currentYear = 2025;

    cout << "Suitable cars:\n";
    Node3* temp = head;

    while (temp) {
        if ((currentYear - temp->year > 10) && (temp->price < 5000)) {
            cout << temp->name << " " << temp->year << " " << temp->price << endl;
        }
        temp = temp->next;
    }

    while (head) {
        Node3* t = head;
        head = head->next;
        delete t;
    }
}

int main() {
    int choice;

    do {
        cout << "\n--- MENU ---\n";
        cout << "1 - List (4 elements)\n";
        cout << "2 - Cities\n";
        cout << "3 - Cars\n";
        cout << "0 - Exit\n";
        cout << "Your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: task1(); break;
            case 2: task2(); break;
            case 3: task3(); break;
            case 0: cout << "Exit...\n"; break;
            default: cout << "Error!\n";
        }

    } while (choice != 0);

    return 0;
}