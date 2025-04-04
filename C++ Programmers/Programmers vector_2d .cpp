#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<vector<int>> v1;  // Empty 2D vector

    int rows = 3;
    int cols = 4;

    vector<vector<int>> v2(rows, vector<int>(cols)); // 3×4 size, default value 0
    vector<vector<int>> v3(rows, vector<int>(cols, 9)); // 3×4 size, all values 9

    vector<vector<int>> v4 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    }; // Manual initialization

    // Printing the vectors
    cout << "v2 (initialized with 0):\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << v2[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nv3 (initialized with 9):\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << v3[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nv4 (manually initialized):\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < 3; j++) {  // Only 3 columns in v4
            cout << v4[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}