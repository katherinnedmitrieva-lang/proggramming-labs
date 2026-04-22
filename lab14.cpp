#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void countCharacters() {
    string text;
    cout << "Enter a line: ";
    cin.ignore();
    getline(cin, text);

    if (text.empty()) {
        cout << "Empty input!\n";
        return;
    }

    map<char, int> freq;

    for (char c : text) {
        freq[c]++;
    }

    cout << "\nCharacters count:\n";
    for (auto p : freq) {
        cout << p.first << " : " << p.second << endl;
    }

    char mostChar;
    int maxCount = 0;

    for (auto p : freq) {
        if (p.second > maxCount) {
            maxCount = p.second;
            mostChar = p.first;
        }
    }

    cout << "Most frequent: " << mostChar << " (" << maxCount << " times)\n";
}

void warehouseMenu() {
    map<string, int> goods;
    int choice;

    do {
        cout << "\nWarehouse Menu:\n";
        cout << "1. Add product\n2. Update quantity\n3. Delete product\n4. Find product\n5. Show all\n0. Back\n";
        cin >> choice;

        string name;
        int qty;

        switch (choice) {
        case 1:
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter quantity: ";
            cin >> qty;

            if (qty < 0) {
                cout << "Invalid quantity!\n";
                break;
            }

            goods[name] = qty;
            break;

        case 2:
            cout << "Enter name: ";
            cin >> name;

            if (goods.count(name)) {
                cout << "Enter new quantity: ";
                cin >> qty;

                if (qty < 0) {
                    cout << "Invalid quantity!\n";
                    break;
                }

                goods[name] = qty;
            } else {
                cout << "Not found!\n";
            }
            break;

        case 3:
            cout << "Enter name: ";
            cin >> name;

            if (goods.erase(name))
                cout << "Deleted!\n";
            else
                cout << "Not found!\n";
            break;

        case 4:
            cout << "Enter name: ";
            cin >> name;

            if (goods.count(name))
                cout << name << " : " << goods[name] << endl;
            else
                cout << "Not found!\n";
            break;

        case 5:
            cout << "\nAll products:\n";
            for (auto p : goods)
                cout << p.first << " : " << p.second << endl;
            break;
        }

    } while (choice != 0);
}

struct Student {
    string name;
    string group;
    double average;
};

void studentMenu() {
    vector<Student> students;
    int choice;

    do {
        cout << "\nStudent Menu:\n";
        cout << "1. Add student\n2. Delete by name\n3. Sort by average\n4. Find by group\n5. Above average\n6. Show all\n0. Back\n";
        cin >> choice;

        string name, group;
        double avg;

        switch (choice) {
        case 1:
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter group: ";
            cin >> group;
            cout << "Enter average: ";
            cin >> avg;

            if (avg < 0 || avg > 100) {
                cout << "Invalid average!\n";
                break;
            }

            students.push_back({name, group, avg});
            break;

        case 2:
            cout << "Enter name: ";
            cin >> name;

            students.erase(
                remove_if(students.begin(), students.end(),
                    [name](Student s) { return s.name == name; }),
                students.end()
            );
            break;

        case 3:
            sort(students.begin(), students.end(),
                [](Student a, Student b) {
                    return a.average > b.average;
                });
            cout << "Sorted!\n";
            break;

        case 4:
            cout << "Enter group: ";
            cin >> group;

            for (auto s : students) {
                if (s.group == group)
                    cout << s.name << " " << s.average << endl;
            }
            break;

        case 5:
            cout << "Enter threshold: ";
            cin >> avg;

            for (auto s : students) {
                if (s.average > avg)
                    cout << s.name << " " << s.average << endl;
            }
            break;

        case 6:
            for (auto s : students)
                cout << s.name << " " << s.group << " " << s.average << endl;
            break;
        }

    } while (choice != 0);
}

void groupWords() {
    multimap<int, string> words;
    int n;

    cout << "How many words? ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid number!\n";
        return;
    }

    string word;

    for (int i = 0; i < n; i++) {
        cin >> word;
        words.insert({word.length(), word});
    }

    cout << "\nGrouped words:\n";

    int currentLength = -1;
    int count = 0;

    for (auto p : words) {
        if (p.first != currentLength) {
            if (currentLength != -1)
                cout << "(count: " << count << ")\n";

            currentLength = p.first;
            count = 0;

            cout << "\nLength " << currentLength << ": ";
        }

        cout << p.second << " ";
        count++;
    }

    if (count > 0)
        cout << "(count: " << count << ")\n";
}

int main() {
    int choice;

    do {
        cout << "\nMAIN MENU:\n";
        cout << "1. Count characters\n";
        cout << "2. Warehouse\n";
        cout << "3. Students\n";
        cout << "4. Group words\n";
        cout << "0. Exit\n";

        cin >> choice;

        switch (choice) {
        case 1: countCharacters(); break;
        case 2: warehouseMenu(); break;
        case 3: studentMenu(); break;
        case 4: groupWords(); break;
        case 0: cout << "Goodbye!\n"; break;
        default: cout << "Invalid choice!\n";
        }

    } while (choice != 0);

    return 0;
}