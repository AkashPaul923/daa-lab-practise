#include <iostream>
#include <climits>

using namespace std;

int main() {
    int n;
    cout << "Enter the size of the matrix: ";
    cin >> n;

    int w[10][10];
    int q[10][10];

    cout << "Enter the value of the matrix:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> w[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (w[i][j] == 0 && i != j) {
                q[i][j] = INT_MAX / 2; // Use INT_MAX/2 to prevent overflow during addition
            } else {
                q[i][j] = w[i][j];
            }
        }
    }

    cout << "The initial matrix is:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (q[i][j] == INT_MAX / 2)
                cout << "\tINF";
            else
                cout << "\t" << q[i][j];
        }
        cout << endl;
    }

    for (int k = 0; k < n; ++k) {
        cout << "\nMatrix after considering vertex " << k + 1 << " as an intermediate vertex:" << endl;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (q[i][k] + q[k][j] < q[i][j]) {
                    q[i][j] = q[i][k] + q[k][j];
                }
                if (q[i][j] == INT_MAX / 2)
                    cout << "\tINF";
                else
                    cout << "\t" << q[i][j];
            }
            cout << endl;
        }
    }

    return 0;
}

