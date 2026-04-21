#include <iostream>
using namespace std;

const int N = 7;

void printMatrix(int a[N][N]) {
    cout << "\nAdjacency matrix:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

int countEdges(int a[N][N]) {
    int count = 0;
    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++)
            if (a[i][j] != 0) count++;
    return count;
}

void findDegrees(int a[N][N]) {
    int deg[N];

    for (int i = 0; i < N; i++) {
        deg[i] = 0;
        for (int j = 0; j < N; j++) {
            if (a[i][j] != 0) deg[i]++;
        }
    }

    cout << "\nDegrees:\n";
    for (int i = 0; i < N; i++) {
        cout << "Vertex " << i + 1 << ": " << deg[i] << endl;
    }

    int max = deg[0], min = deg[0];
    for (int i = 1; i < N; i++) {
        if (deg[i] > max) max = deg[i];
        if (deg[i] < min) min = deg[i];
    }

    cout << "\nMax degree: " << max << endl;
    cout << "Min degree: " << min << endl;

    cout << "\nSame degrees:\n";
    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++)
            if (deg[i] == deg[j])
                cout << i + 1 << " and " << j + 1 << endl;
}

void findMaxEdge(int a[N][N]) {
    int max = 0, u = 0, v = 0;

    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++)
            if (a[i][j] > max) {
                max = a[i][j];
                u = i;
                v = j;
            }

    cout << "\nLongest edge: " << u + 1 << " - " << v + 1;
    cout << " (weight = " << max << ")" << endl;
}

void findMinTriple(int a[N][N]) {
    int minSum = 1000000;
    int x = 0, y = 0, z = 0;

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            for (int k = j + 1; k < N; k++) {

                int sum = 0;

                if (a[i][j] != 0 && a[i][k] != 0 && a[j][k] != 0) {
                    sum = a[i][j] + a[i][k] + a[j][k];

                    if (sum < minSum) {
                        minSum = sum;
                        x = i;
                        y = j;
                        z = k;
                    }
                }
            }
        }
    }

    cout << "\n3 vertices with minimum sum:\n";
    cout << x + 1 << ", " << y + 1 << ", " << z + 1;
    cout << " (sum = " << minSum << ")" << endl;
}

int main() {
    int a[N][N] = {0};
    int choice;

    cout << "1 - Use ready graph\n";
    cout << "2 - Enter manually\n";
    cin >> choice;

    if (choice == 1) {
        a[0][2] = a[2][0] = 3;
        a[0][6] = a[6][0] = 10;
        a[1][2] = a[2][1] = 6;
        a[1][3] = a[3][1] = 1;
        a[2][3] = a[3][2] = 5;
        a[2][4] = a[4][2] = 2;
        a[2][5] = a[5][2] = 8;
        a[5][6] = a[6][5] = 11;
    }
    else {
        int m;
        cout << "Enter number of edges: ";
        cin >> m;

        cout << "Enter: v1 v2 weight\n";
        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            a[u - 1][v - 1] = w;
            a[v - 1][u - 1] = w;
        }
    }

    printMatrix(a);

    cout << "\nNumber of edges: " << countEdges(a) << endl;

    findDegrees(a);

    findMaxEdge(a);

    findMinTriple(a);

    return 0;
}