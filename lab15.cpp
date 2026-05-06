#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

// Бульбашка
void bubble(vector<int>& a) {
    for (int i = 0; i < a.size(); i++)
        for (int j = 0; j < a.size() - 1; j++)
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
}

// Вставка
void insertion(vector<int>& a) {
    for (int i = 1; i < a.size(); i++) {
        int key = a[i], j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

// Вибір
void selection(vector<int>& a) {
    for (int i = 0; i < a.size(); i++) {
        int min = i;
        for (int j = i + 1; j < a.size(); j++)
            if (a[j] < a[min]) min = j;
        swap(a[i], a[min]);
    }
}

// Гном
void gnome(vector<int>& a) {
    int i = 0;
    while (i < a.size()) {
        if (i == 0 || a[i] >= a[i - 1]) i++;
        else {
            swap(a[i], a[i - 1]);
            i--;
        }
    }
}

// Генерація масиву
vector<int> create(int n) {
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        a[i] = rand() % 1000;
    return a;
}

// Вимір часу
double test(void (*sortFunc)(vector<int>&), vector<int> a) {
    clock_t start = clock();
    sortFunc(a);
    clock_t end = clock();
    return (double)(end - start) / CLOCKS_PER_SEC;
}

int main() {
    srand(time(0));
    int sizes[] = {1000, 10000, 100000};

    for (int n : sizes) {
        vector<int> a = create(n);

        cout << "\nn = " << n << endl;
        cout << "Bubble: " << test(bubble, a) << endl;
        cout << "Insertion: " << test(insertion, a) << endl;
        cout << "Selection: " << test(selection, a) << endl;
        cout << "Gnome: " << test(gnome, a) << endl;
    }
}