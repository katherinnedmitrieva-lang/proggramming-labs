#include <iostream>
#include <cstring>
#include <ctime>
using namespace std;


struct Worker {
    string surname;
    string initials;
    string position;
    int year;
    double salary;
};

int inputInt() {
    int x;
    while (!(cin >> x)) {
        cout << "Error!Input other number: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }
    return x;
}

double inputDouble() {
    double x;
    while (!(cin >> x)) {
        cout << "Error!Input othe number: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }
    return x;
}

int calcExperience(int year, int currentYear) {
    if (currentYear < year) return 0;
    	
    return currentYear - year;
}

double salaryWithTax(double salary) {
    return salary * 0.67;
}

void task1() {
    cout << "\n===== Task 1 =====\n";
    int n;
    cout << "Number of employees: ";
    n = inputInt();

    Worker workers[100];

    for (int i = 0; i < n; i++) {
        cout << "\nEmployee " << i + 1 << endl;
        cout << "Surname: ";
        cin >> workers[i].surname;
        cout << "Initials: ";
        cin >> workers[i].initials;
        cout << "Position: ";
        cin >> workers[i].position;
        cout << "Year of admission: ";
        workers[i].year = inputInt();
        cout << "Salary: ";
        workers[i].salary = inputDouble();
    }

    cout << "\nInformation about workers:\n";
    for (int i = 0; i < n; i++) {
        cout << workers[i].surname << " "
             << workers[i].initials
             << " | Experience: " << experience(workers[i].year)
             << " years | Salary after tax: "
             << salaryWithTax(workers[i].salary)
             << endl;
    }
}

enum Faculty {
    IT = 1,
    ECONOMICS,
    LAW,
    MANAGEMENT
};

struct Student {
    string surname;
    int course;
    double average;
    Faculty faculty;
};

void task2() {
    cout << "\n===== Task 2 =====\n";

    const int n = 5;
    Student group[n];

    for (int i = 0; i < n; i++) {
        cout << "\nStudent" << i + 1 << endl;
        cout << "Surname: ";
        cin >> group[i].surname;
        cout << "Course: ";
        group[i].course = inputInt();
        cout << "Average score: ";
        group[i].average = inputDouble();

        int f;
        do {
            cout << "Faculty (1-IT, 2-ECON, 3-LAW, 4-MANAG): ";
            f = inputInt();
        } while (f < 1 || f > 4);

        group[i].faculty = (Faculty)f;
    }

    int chosen;
    cout << "\nEnter the faculty to search: ";
    chosen = inputInt();

    cout << "\nStudents of the selected faculty:\n";
    for (int i = 0; i < n; i++)
        if (group[i].faculty == chosen)
            cout << group[i].surname << endl;

    double sum = 0;
    for (int i = 0; i < n; i++)
        sum += group[i].average;

    cout << "Average score of the group: " << sum / n << endl;
}

enum PaymentType {
    CASH = 1,
    CARD,
    TRANSFER
};

union PaymentInfo {
    char cardNumber[20];
    char bankAccount[20];
};

struct Payment {
    int number;
    PaymentType type;
    PaymentInfo info;
};

void task3() {
    cout << "\n===== Task 3 =====\n";

    const int n = 3;
    Payment payments[n];

    int cashCount = 0, cardCount = 0, transferCount = 0;

    for (int i = 0; i < n; i++) {
        cout << "\nPayment" << i + 1 << endl;
        cout << "payment number: ";
        payments[i].number = inputInt();

        int t;
        do {
            cout << " Type (1-CASH, 2-CARD, 3-TRANSFER): ";
            t = inputInt();
        } while (t < 1 || t > 3);

        payments[i].type = (PaymentType)t;

        if (payments[i].type == CASH) {
            cashCount++;
        }
        else if (payments[i].type == CARD) {
            cout << "Card number: ";
            cin >> payments[i].info.cardNumber;
            cardCount++;
        }
        else {
            cout << "Bank account: ";
            cin >> payments[i].info.bankAccount;
            transferCount++;
        }
    }

    cout << "\nPayment statistics:\n";
    cout << "Cash: " << cashCount << endl;
    cout << "Card: " << cardCount << endl;
    cout << "Bank transfers: " << transferCount << endl;
}

int main() {
    task1();
    task2();
    task3();
    return 0;
}