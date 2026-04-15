#include <iostream>
#include <string>
using namespace std;

struct TempNode {
    string date;
    double temp;
    TempNode* next;
    TempNode* prev;
};

void addTemp(TempNode*& head, string date, double temp) {
    TempNode* newNode = new TempNode{date, temp, nullptr, nullptr};

    if (!head) {
        head = newNode;
        return;
    }

    TempNode* tempPtr = head;
    while (tempPtr->next)
        tempPtr = tempPtr->next;

    tempPtr->next = newNode;
    newNode->prev = tempPtr;
}

void printTempList(TempNode* head) {
    while (head) {
        cout << head->date << " : " << head->temp << endl;
        head = head->next;
    }
}

void mergeLists(TempNode*& list1, TempNode* list2) {
    if (!list1) {
        list1 = list2;
        return;
    }

    TempNode* temp = list1;
    while (temp->next)
        temp = temp->next;

    temp->next = list2;
    if (list2)
        list2->prev = temp;
}

void findMinMax(TempNode* head) {
    if (!head) {
        cout << "List is empty!\n";
        return;
    }

    double min = head->temp;
    double max = head->temp;

    while (head) {
        if (head->temp < min) min = head->temp;
        if (head->temp > max) max = head->temp;
        head = head->next;
    }

    cout << "Min temperature: " << min << endl;
    cout << "Max temperature: " << max << endl;
}

void deleteTempList(TempNode*& head) {
    while (head) {
        TempNode* temp = head;
        head = head->next;
        delete temp;
    }
}

struct Employee {
    string surname;
    string department;
    double salary;
    Employee* next;
    Employee* prev;
};

void addEmployee(Employee*& head, string surname, string dept, double salary) {
    Employee* newNode = new Employee{surname, dept, salary, nullptr, nullptr};

    if (!head) {
        head = newNode;
        return;
    }

    Employee* temp = head;
    while (temp->next)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

void printForward(Employee* head) {
    while (head) {
        cout << head->surname << " | " << head->department << " | " << head->salary << endl;
        if (!head->next) break;
        head = head->next;
    }
}

void printBackward(Employee* tail) {
    while (tail) {
        cout << tail->surname << " | " << tail->department << " | " << tail->salary << endl;
        tail = tail->prev;
    }
}

double calculateAverage(Employee* head) {
    int count = 0;
    double sum = 0;

    while (head) {
        sum += head->salary;
        count++;
        head = head->next;
    }

    if (count == 0) return 0;
    return sum / count;
}

void splitList(Employee* head, Employee*& above, Employee*& below) {
    double avg = calculateAverage(head);

    while (head) {
        if (head->salary > avg)
            addEmployee(above, head->surname, head->department, head->salary);
        else
            addEmployee(below, head->surname, head->department, head->salary);

        head = head->next;
    }

    cout << "Average salary: " << avg << endl;
}

void deleteEmployeeList(Employee*& head) {
    while (head) {
        Employee* temp = head;
        head = head->next;
        delete temp;
    }
}

void temperatureMenu() {
    TempNode* list1 = nullptr;
    TempNode* list2 = nullptr;

    int n;
    cout << "Enter number of elements for first list: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        string date;
        double t;
        cout << "Enter date and temperature: ";
        cin >> date >> t;
        addTemp(list1, date, t);
    }

    cout << "Enter number of elements for second list: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        string date;
        double t;
        cout << "Enter date and temperature: ";
        cin >> date >> t;
        addTemp(list2, date, t);
    }

    mergeLists(list1, list2);

    cout << "\nMerged list:\n";
    printTempList(list1);

    findMinMax(list1);

    deleteTempList(list1);
}

void employeeMenu() {
    Employee* mainList = nullptr;
    Employee* above = nullptr;
    Employee* below = nullptr;

    int n;
    cout << "Enter number of employees: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        string name, dept;
        double salary;

        cout << "Enter surname, department, salary: ";
        cin >> name >> dept >> salary;

        addEmployee(mainList, name, dept, salary);
    }

    splitList(mainList, above, below);

    cout << "\nAbove average:\n";
    printForward(above);

    cout << "\nBelow or equal average:\n";
    printForward(below);

    Employee* tail = above;
    while (tail && tail->next) tail = tail->next;

    cout << "\nReverse (above):\n";
    printBackward(tail);

    string name, dept;
    double salary;
    cout << "\nAdd new employee (surname dept salary): ";
    cin >> name >> dept >> salary;

    addEmployee(above, name, dept, salary);

    cout << "\nUpdated above list:\n";
    printForward(above);

    deleteEmployeeList(mainList);
    deleteEmployeeList(above);
    deleteEmployeeList(below);
}

int main() {
    int choice;

    do {
        cout << "\n===MENU===\n";
        cout << "1 - Temperature task\n";
        cout << "2 - Employee task\n";
        cout << "0 - Exit\n";
        cout << "Choose: ";
        cin >> choice;

        if (choice == 1)
            temperatureMenu();
        else if (choice == 2)
            employeeMenu();
        else if (choice != 0)
            cout << "Invalid choice!\n";

    } while (choice != 0);

    return 0;
}