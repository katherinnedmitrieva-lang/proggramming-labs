#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int inputInt() {
    int x;
    while (!(cin >> x)) {
        cout << "Error: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }
    return x;
}

void bubbleSort(int a[], int n, bool ascending) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (ascending) {
                if (a[j] > a[j + 1])
                    swap(a[j], a[j + 1]);
            } else {
                if (a[j] < a[j + 1])
                    swap(a[j], a[j + 1]);
            }
        }
    }
}


void task1() {
    cout << "\n--- Task 1 ---\n";
    cout << "n: ";
    int n = inputInt();

    int* a = new int[n];

    cout << "Input elements:\n";
    for (int i = 0; i < n; i++)
        a[i] = inputInt();

    int* temp = new int[n];
    int k = 0;

    for (int i = 0; i < n; i++)
        if (a[i] % 2 == 0)
            temp[k++] = a[i];

    bubbleSort(temp, k, true);

    int start = k;
    for (int i = 0; i < n; i++)
        if (a[i] % 2 != 0)
            temp[k++] = a[i];

    bubbleSort(temp + start, k - start, false);

    cout << "Result:\n";
    for (int i = 0; i < n; i++)
        cout << temp[i] << " ";

    delete[] a;
    delete[] temp;
}

void task2() {
    cout << "\n--- Task 2 ---\n";
    cout << "n: ";
    int n = inputInt();

    int* a = new int[n];
    srand(time(0));

    for (int i = 0; i < n; i++) {
        bool unique;
        do {
            unique = true;
            a[i] = rand() % 100;
            for (int j = 0; j < i; j++)
                if (a[i] == a[j])
                    unique = false;
        } while (!unique);
    }

    cout << "Matrix:\n";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    cout << "\nInput X: ";
    int X = inputInt();

    int count = 0;
    for (int i = 0; i < n; i++)
        if (a[i] <= X)
            count++;

    cout << "New (add 0):\n";
    for (int i = 0; i < n; i++)
        if (a[i] > X)
            cout << a[i] + 0 << " ";


    delete[] a;
}

void task3() {
    cout << "\n--- Task 3 ---\n";

    int a[5][5];
    srand(time(0));

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            a[i][j] = rand() % 100;

    cout << "Start matrix:\n";
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++)
            cout << a[i][j] << "\t";
        cout << endl;
    }

    int max = a[0][0], row = 0, col = 0;

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            if (a[i][j] > max) {
                max = a[i][j];
                row = i;
                col = j;
            }

    for (int j = 0; j < 5; j++)
        swap(a[0][j], a[row][j]);

    for (int i = 0; i < 5; i++)
        swap(a[i][0], a[i][col]);

    cout << "\nAfter:\n";
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++)
            cout << a[i][j] << "\t";
        cout << endl;
    }


}

void task4() {
    cout << "\n--- Task 4 ---\n";
    cout << "Input matrix size: ";
    int n = inputInt();

    int** a = new int*[n];
    for (int i = 0; i < n; i++)
        a[i] = new int[n];

    cout << "Input elements:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = inputInt();

    for (int i = 0; i < n; i++)
        a[i][i] = 0;

    int max = a[0][0], row = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (a[i][j] > max) {
                max = a[i][j];
                row = i;
            }

    cout << "\nResult:\n";
    for (int i = 0; i < n; i++) {
        if (i == row) continue;
        for (int j = 0; j < n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }

    for (int i = 0; i < n; i++)
        delete[] a[i];
    delete[] a;
}

int main() {
    task1();
    task2();
    task3();
    task4();
    return 0;
}