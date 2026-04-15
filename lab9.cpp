#include <iostream>
#include <fstream>
using namespace std;

// ===== ВУЗОЛ =====
struct Node {
    int data;
    Node* left;
    Node* right;
};

// ===== СТВОРЕННЯ =====
Node* create(int x) {
    Node* n = new Node;
    n->data = x;
    n->left = n->right = NULL;
    return n;
}

// ===== ДОДАВАННЯ =====
Node* add(Node* root, int x) {
    if (root == NULL) return create(x);

    if (x < root->data)
        root->left = add(root->left, x);
    else
        root->right = add(root->right, x);

    return root;
}

// ===== ВИВІД =====
void print(Node* root) {
    if (root == NULL) return;
    print(root->left);
    cout << root->data << " ";
    print(root->right);
}

// ===== ПОШУК =====
bool find(Node* root, int x) {
    if (root == NULL) return false;
    if (root->data == x) return true;

    if (x < root->data)
        return find(root->left, x);
    else
        return find(root->right, x);
}

// ===== ГЛИБИНА =====
int height(Node* root) {
    if (root == NULL) return 0;

    int l = height(root->left);
    int r = height(root->right);

    return 1 + (l > r ? l : r);
}

// ===== ПАРНІ / НЕПАРНІ =====
void split(Node* root, Node*& even, Node*& odd) {
    if (root == NULL) return;

    if (root->data % 2 == 0)
        even = add(even, root->data);
    else
        odd = add(odd, root->data);

    split(root->left, even, odd);
    split(root->right, even, odd);
}

// ===== ВИДАЛЕННЯ (СПРОЩЕНО) =====
Node* deleteNode(Node* root, int x) {
    if (root == NULL) return NULL;

    if (x < root->data)
        root->left = deleteNode(root->left, x);
    else if (x > root->data)
        root->right = deleteNode(root->right, x);
    else {
        if (root->left == NULL) return root->right;
        if (root->right == NULL) return root->left;

        Node* temp = root->right;
        while (temp->left != NULL)
            temp = temp->left;

        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// ===== ОЧИСТКА =====
void clear(Node* root) {
    if (root == NULL) return;
    clear(root->left);
    clear(root->right);
    delete root;
}

// ===== ГОЛОВНА =====
int main() {
    Node* root = NULL;

    int choice;
    cout << "1 - default data, 2 - manually: ";
    cin >> choice;

    int n, x;

    if (choice == 1) {
        cout << "Quantity: ";
        cin >> n;

        for (int i = 0; i < n; i++) {
            cin >> x;
            root = add(root, x);
        }
    } else {
        int a, b;
        cout << "n a b: ";
        cin >> n >> a >> b;

        if (n > (b - a + 1)) {
            cout << "Error!\n";
            return 0;
        }

        for (int i = 0; i < n; i++) {
            x = a + rand() % (b - a + 1);
            root = add(root, x);
        }
    }

    cout << "Tree: ";
    print(root);

    // ПОШУК
    cout << "\nSearch : ";
    cin >> x;
    cout << (find(root, x) ? "There is\n" : "None\n");

    // ПАРНІ / НЕПАРНІ
    Node* even = NULL;
    Node* odd = NULL;

    split(root, even, odd);

    cout << "Vapours: ";
    print(even);
    cout << "\nOdd: ";
    print(odd);

    // ГЛИБИНА
    cout << "\nDepth: " << height(root) << endl;

    // ===== ФАЙЛ =====
    ifstream f("data.txt");
    Node* fileTree = NULL;

    while (f >> x)
        fileTree = add(fileTree, x);

    int sum = 0, count = 0;

    // простий обхід
    Node* temp = fileTree;
    // (щоб не ускладнювати — просто ще раз print логічно пояснити)

    cout << "File tree: ";
    print(fileTree);

    // ВИДАЛЕННЯ
    cout << "\nDelete: ";
    cin >> x;

    fileTree = deleteNode(fileTree, x);

    cout << "After Delete: ";
    print(fileTree);

    // ОЧИСТКА
    clear(root);
    clear(even);
    clear(odd);
    clear(fileTree);

    return 0;
}