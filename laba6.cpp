#include <iostream>
#include <stack>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

void task1() {
    stack<double> st, temp;
    int n;

    cout << "Number of elements: ";
    cin >> n;
    if (n <= 0) return;

    srand(time(0));

    cout << "Generated numbers:\n";
    for (int i = 0; i < n; i++) {
        double x = -6 + (rand() % 1700) / 100.0;
        st.push(x);
        cout << x << endl;
    }

    double k;
    cout << "Enter the number: ";
    cin >> k;

    while (!st.empty()) {
        if (st.top() >= k)
            temp.push(st.top());
        st.pop();
    }

    double sum = 0;
    int count = 0;

    cout << "Remained in the stack:\n";
    while (!temp.empty()) {
        cout << temp.top() << endl;
        sum += temp.top();
        count++;
        temp.pop();
    }

    if (count > 0)
        cout << "Average: " << sum / count << endl;
    else
        cout << "Stack is empty!\n";
}

struct Music {
    string type, name, artist;
    int duration, count;
    double price;
};

void task2() {
    stack<Music> st;
    int n;

    cout << "Number of records: ";
    cin >> n;
    if (n <= 0) return;

    for (int i = 0; i < n; i++) {
        Music m;
        cout << "Enter (type name artist time quantity price):\n";
        cin >> m.type >> m.name >> m.artist >> m.duration >> m.count >> m.price;
        st.push(m);
    }

    string search;
    cout << "Artist: ";
    cin >> search;

    int totalTime = 0;
    double totalPrice = 0;
    int cassetteCount = 0;

    while (!st.empty()) {
        Music m = st.top();

        cout << m.name << " (" << m.artist << ")\n";

        if (m.artist == search)
            totalTime += m.duration;

        if (m.type == "cassette") {
            totalPrice += m.price;
            cassetteCount++;
        }

        st.pop();
    }

    cout << "Total time: " << totalTime << endl;

    if (cassetteCount > 0)
        cout << "Average price of cassettes: " << totalPrice / cassetteCount << endl;
    else
        cout << "There are no cassettes!\n";
}

void task3() {
    queue<int> q, newQ;
    int n;

    cout << "Number of elements: ";
    cin >> n;
    if (n <= 0) return;

    srand(time(0));

    cout << "Initial queue:\n";
    for (int i = 0; i < n; i++) {
        int x = rand() % 20 + 1;
        q.push(x);
        cout << x << " ";
    }
    cout << endl;

    while (!q.empty()) {
        int x = q.front();
        newQ.push(x);

        if (x % 2 == 0)
            newQ.push(100);

        q.pop();
    }

    double product = 1;
    int count = 0;

    cout << "New queue:\n";
    while (!newQ.empty()) {
        int x = newQ.front();
        cout << x << " ";
        product *= x;
        count++;
        newQ.pop();
    }

    cout << endl;

    if (count > 0)
        cout << "Geometric mean: " << pow(product, 1.0 / count) << endl;
}

struct Team {
    string name, city;
    int points;
};

void task4() {
    queue<Team> q;
    int n;

    cout << "Number of teams: ";
    cin >> n;
    if (n <= 0) return;

    for (int i = 0; i < n; i++) {
        Team t;
        cout << "Enter (name city points):\n";
        cin >> t.name >> t.city >> t.points;
        q.push(t);
    }

    string cities[100];
    int cityCount = 0;

    Team leader, outsider;
    bool first = true;

    while (!q.empty()) {
        Team t = q.front();

        bool found = false;
        for (int i = 0; i < cityCount; i++)
            if (cities[i] == t.city)
                found = true;

        if (!found)
            cities[cityCount++] = t.city;

        if (first) {
            leader = outsider = t;
            first = false;
        } else {
            if (t.points > leader.points) leader = t;
            if (t.points < outsider.points) outsider = t;
        }

        q.pop();
    }

    cout << "Cities:\n";
    for (int i = 0; i < cityCount; i++)
        cout << cities[i] << endl;

    cout << "Leader: " << leader.name << " (" << leader.points << ")\n";
    cout << "Outsider: " << outsider.name << " (" << outsider.points << ")\n";
}

int main() {
    int choice;

    do {
        cout << "\n=== Menu ===\n";
        cout << "1 - Stack (numbers)\n";
        cout << "2 - Stack (music)\n";
        cout << "3 - Queue (100 + geometric mean)\n";
        cout << "4 - Queue (teams)\n";
        cout << "0 - Exit\n";
        cout << "Your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: task1(); break;
            case 2: task2(); break;
            case 3: task3(); break;
            case 4: task4(); break;
            case 0: cout << "Exit...\n"; break;
            default: cout << "Error!\n";
        }

    } while (choice != 0);

    return 0;
}