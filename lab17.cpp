#include <iostream>
using namespace std;

struct Student {
    string name;
    int group;
    int m[4];
    double avg;
};
void calc(Student &s) {
    s.avg = (s.m[0] + s.m[1] + s.m[2] + s.m[3]) / 4.0;
}
void sortAvg(Student a[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (a[j].avg > a[j + 1].avg)
                swap(a[j], a[j + 1]);
}
void sortGroup(Student a[], int n) {
    for (int i = 1; i < n; i++) {
        Student t = a[i];
        int j = i - 1;
        while (j >= 0 && a[j].group < t.group) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = t;
    }
}
void search(Student a[], int n, double x) {
    int l = 0, r = n - 1;
    bool found = false;

    while (l <= r) {
        int m = (l + r) / 2;

        if (a[m].avg == x) {
            // знайшли одного — шукаємо сусідів
            int i = m;
            while (i >= 0 && a[i].avg == x) {
                cout << a[i].name << endl;
                i--;
            }
            i = m + 1;
            while (i < n && a[i].avg == x) {
                cout << a[i].name << endl;
                i++;
            }
            found = true;
            break;
        }

        if (a[m].avg < x) l = m + 1;
        else r = m - 1;
    }

    if (!found) cout << "not found\n";
}
void print(Student a[], int n) {
    for (int i = 0; i < n; i++)
        cout << a[i].name << " " << a[i].group << " " << a[i].avg << endl;
}

int main() {
    const int n = 5;

    Student a[n] = {
        {"Ivan",2,{5,4,5,4}},
        {"Oleg",1,{3,4,3,4}},
        {"Anna",3,{5,5,5,5}},
        {"Nina",2,{4,4,4,4}},
        {"Max",1,{3,3,4,3}}
    };
    for (int i = 0; i < n; i++)
        calc(a[i]);
    sortAvg(a, n);
    cout << "By avg:\n";
    print(a, n);

    Student b[n];
    for (int i = 0; i < n; i++)
        b[i] = a[i];

    sortGroup(b, n);
    cout << "\nBy group:\n";
    print(b, n);

    double x;
    cout << "\nEnter avg: ";
    cin >> x;

    search(a, n, x);
}