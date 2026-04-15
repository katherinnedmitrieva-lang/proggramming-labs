#include <iostream>
#include <string>
using namespace std;

struct Student {
	string name;
	int group;
	int marks[5];
};

double calcAvgMark(Student s) {
	double sum = 0;
	for (int i = 0; i < 5; i++) sum += s.marks[i];
	return sum / 5.0;
}

void showStudentInfo(Student a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i].name << " | group: " << a[i].group
		     << " | avg: " << avg(a[i]) << endl;
	}
}

void good(Student a[], int n) {
	int found = 0;
	for (int i = 0; i < n; i++) {
		if (avg(a[i]) > 4.0) {
			cout << a[i].name << " | " << a[i].group << endl;
			found = 1;
		}
	}
	if (!found) cout << "There are no such students.\n";
}

int vowel(char c) {
	return (c=='A'||c=='E'||c=='I'||c=='O'||c=='U'||
	        c=='a'||c=='e'||c=='i'||c=='o'||c=='u');
}


int getVowelStudents(Student a[], int n, Student b[]) {
	int k = 0;
	for (int i = 0; i < n; i++) {
		if (a[i].name.size() > 0 && vowel(a[i].name[0])) {
			b[k] = a[i];
			k++;
		}
	}
	return k;
}

void sortArr(Student a[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (avg(a[i]) > avg(a[j])) {
				Student t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
		}
	}
}

void del(Student a[], int &n) {
	if (n < 2) {
		cout << "Not enough elements!\n";
		return;
	}

	int min = 0;
	for (int i = 1; i < n; i++) {
		if (avg(a[i]) < avg(a[min])) {
			min = i;
		}
	}

	if (min < n - 1) {
		for (int i = min + 1; i < n - 1; i++) {
			a[i] = a[i + 1];
		}
		n--;
		cout << "Element was deleed.\n";
	} else {
		cout << "No elements after the minimum.\n";
	}
}

int main() {
	int n;
	cout << "Enter the number of students: ";
	cin >> n;

	if (n <= 0 || n > 100) {
		cout << "Error! n\n";
		return 0;
	}

	Student a[100];

	for (int i = 0; i < n; i++) {
		cout << "\nStudent " << i + 1 << endl;
		cout << "Surname: ";
		cin >> a[i].name;

		cout << "Group: ";
		cin >> a[i].group;

		cout << "5 marks:\n";
		for (int j = 0; j < 5; j++) {
			cin >> a[i].marks[j];
		}
	}

	int m;
	do {
		cout << "\n=====MENU=====\n";
		cout << "1. Students with average score > 4\n";
		cout << "2. Srudents on a vowel (new array)\n";
		cout << "3. Sorting\n";
		cout << "4. Delete after min\n";
		cout << "5. Show all\n";
		cout << "0. Exit\n";
		cout << "Choise: ";
		cin >> m;

		switch (m) {
			case 1:
				cout << "\nResult:\n";
				good(a, n);
				break;

			case 2: {
				Student b[100];
				int k = getVowelStudents(a, n, b);

				if (k == 0) {
					cout << "There are no students!\n";
				} else {
					cout << "\nNew array:\n";
					show(b, k);
				}
				break;
			}

			case 3:
				sortArr(a, n);
				cout << "\nAfter sort:\n";
				show(a, n);
				break;

			case 4:
				del(a, n);
				cout << "\nAfter remove:\n";
				show(a, n);
				break;

			case 5:
				show(a, n);
				break;
		}

	} while (m != 0);

	return 0;
}