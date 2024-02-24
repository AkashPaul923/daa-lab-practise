#include <iostream>
using namespace std;

// Function to solve 0/1 knapsack problem
int knapsack(int c, int wt[], int p[], int n) {
    int K[n + 1][c + 1];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= c; j++) {
            if (i == 0 || j == 0)
                K[i][j] = 0;
            else if (wt[i - 1] <= j)
                K[i][j] = max(p[i - 1] + K[i - 1][j - wt[i - 1]], K[i - 1][j]);
            else
                K[i][j] = K[i - 1][j];
        }
    }
    return K[n][c];
}

// Main function
int main() {
    int n, c;
    cout << "Enter number of elements: ";
    cin >> n;
    int p[n], wt[n];

    cout << "Enter the weights and profits of the elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> wt[i] >> p[i];
    }

    cout << "Enter the capacity of knapsack: ";
    cin >> c;

    int max_profit = knapsack(c, wt, p, n);
    cout << "The maximum profit that can be obtained is: " << max_profit << endl;

    return 0;
}
