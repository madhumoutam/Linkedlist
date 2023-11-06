#include <iostream>
using namespace std;

int main() {
    int sparseMatrix[4][5] = {0};

    int inputData[6][3] = {
        {0, 2, 3},//
        {0, 4, 4},
        {1, 2, 5},
        {1, 3, 7},
        {3, 1, 2},
        {3, 2, 6}
    };

    for (int i = 0; i < 6; i++) {
        int row = inputData[i][0];
        int col = inputData[i][1];
        int value = inputData[i][2];
        sparseMatrix[row][col] = value;
    }

    int compactMatrix[3][6];
    int k = 0;


    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            if (sparseMatrix[i][j] != 0) {
                compactMatrix[0][k] = i;
                compactMatrix[1][k] = j;
                compactMatrix[2][k] = sparseMatrix[i][j];
                k++;
            }
        }
    }


    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            int found = 0;
            for (int k = 0; k < 6; k++) {
                if (compactMatrix[0][k] == i && compactMatrix[1][k] == j) {
                    cout << compactMatrix[2][k] << " ";
                    found = 1;
                }
            }
            if (!found) {
                cout << "0 ";
            }
        }
        cout << endl;
    }

    return 0;
}
