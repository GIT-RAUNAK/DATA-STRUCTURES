// LINK 2D MATRIX INTO A 2D LINKED LIST

#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* right;
    Node* down;

    Node(int x) {
        data = x;
        right = nullptr;
        down = nullptr;
    }
};

Node* linkMatrix(vector<vector<int>>& mat) {
    int rows = mat.size();
    if (rows == 0) return nullptr;
    int cols = mat.size();
    vector<vector<Node*>> gridNodes(rows, vector<Node*>(cols, nullptr));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            gridNodes[i][j] = new Node(mat[i][j]);
        }
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (j + 1 < cols) {
                gridNodes[i][j]->right = gridNodes[i][j + 1];
            }
            if (i + 1 < rows) {
                gridNodes[i][j]->down = gridNodes[i + 1][j];
            }
        }
    }
    return gridNodes[0][0];
}

int main() {
    int rows, cols;
    cout << "Enter number of rows and columns: ";
    cin >> rows >> cols;

    vector<vector<int>> mat(rows, vector<int>(cols));
    cout << "Enter elements row by row:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> mat[i][j];
        }
    }

    Node* head = linkMatrix(mat);

    cout << "After Linking Matrix (Row-wise verification):\n";
    Node* rowTemp = head;
    while (rowTemp != nullptr) {
        Node* colTemp = rowTemp;
        while (colTemp != nullptr) {
            cout << colTemp->data << " ";
            colTemp = colTemp->right;
        }
        cout << endl;
        rowTemp = rowTemp->down;
    }

    return 0;
}
