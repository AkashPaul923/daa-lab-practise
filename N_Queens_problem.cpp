#include <iostream>
#include <cmath>

using namespace std;

int board[20], count;

void print(int n);
bool place(int row, int column);
void queen(int row, int n);

int main() {
    int n;
    cout << " - N Queens Problem Using Backtracking -\n\n";
    cout << "Enter number of Queens: ";
    cin >> n;
    queen(1, n);
    return 0;
}

void print(int n) {
    int i, j;
    cout << "\n\nSolution " << ++count << ":\n\n";

    for (i = 1; i <= n; ++i)
        cout << "\t" << i;

    for (i = 1; i <= n; ++i) {
        cout << "\n\n" << i;
        for (j = 1; j <= n; ++j) {
            if (board[i] == j)
                cout << "\tQ"; // queen at i,j position
            else
                cout << "\t-"; // empty slot
        }
    }
    cout << endl;
}

// Function to check conflicts
// If no conflict for desired position returns true otherwise returns false
bool place(int row, int column) {
    for (int i = 1; i <= row - 1; ++i) {
        // Checking column and diagonal conflicts
        if (board[i] == column)
            return false;
        else if (abs(board[i] - column) == abs(i - row))
            return false;
    }
    return true; // no conflicts
}

// Function to check for proper positioning of queen
void queen(int row, int n) {
    for (int column = 1; column <= n; ++column) {
        if (place(row, column)) {
            board[row] = column; // no conflicts so place queen
            if (row == n) // dead end
                print(n); // printing the board configuration
            else // try queen with next position
                queen(row + 1, n);
        }
    }
}

