#include <iostream>
using namespace std;

class Node {
public:
    int col;
    int value;
    Node* next;

    Node(int c, int v) : col(c), value(v), next(nullptr) {}
};

class SparseMatrix {
private:
    int numRows, numCols;
    Node** rows;

public:
    SparseMatrix(int m, int n) : numRows(m), numCols(n) {
        rows = new Node*[m];
        for (int i = 0; i < m; i++) {
            rows[i] = nullptr;
        }
    }

    // Insert a non-zero element into the sparse matrix
    void insert(int r, int c, int v) {
        if (r >= 0 && r < numRows && c >= 0 && c < numCols) {
            Node* newNode = new Node(c, v);
            newNode->next = rows[r];
            rows[r] = newNode;
        } else {
            cout << "Invalid row or column index." << endl;
        }
    }

    // Display the sparse matrix
    void display() {
        for (int r = 0; r < numRows; r++) {
            Node* current = rows[r];
            for (int c = 0; c < numCols; c++) {
                if (current != nullptr && current->col == c) {
                    cout << current->value << " ";
                    current = current->next;
                } else {
                    cout << "0 ";
                }
            }
            cout << endl;
        }
    }

    // Destructor to release allocated memory
    ~SparseMatrix() {
        for (int i = 0; i < numRows; i++) {
            Node* current = rows[i];
            while (current != nullptr) {
                Node* temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] rows;
    }
};

int main() {
    SparseMatrix matrix(4, 5);

    matrix.insert(0, 2, 3);
    matrix.insert(0, 4, 4);
    matrix.insert(1, 2, 5);
    matrix.insert(1, 3, 7);
    matrix.insert(3, 1, 2);
    matrix.insert(3, 2, 6);

    std::cout << "Sparse Matrix:" << std::endl;
    matrix.display();

    return 0;
}
