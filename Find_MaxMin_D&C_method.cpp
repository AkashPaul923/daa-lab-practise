#include <iostream>

using namespace std;

void findMinMax(int a[], int i, int j, int &min, int &max) {
    if (i == j) {
        min = max = a[i];
    } else if (i == j - 1) {
        if (a[i] < a[j]) {
            max = a[j];
            min = a[i];
        } else {
            max = a[i];
            min = a[j];
        }
    } else {
        int mid = (i + j) / 2;
        int min1, max1;

        findMinMax(a, i, mid, min1, max1);
        findMinMax(a, mid + 1, j, min, max);

        if (min > min1) {
            min = min1;
        }
        if (max < max1) {
            max = max1;
        }
    }
}

int main() {
    int n;

    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int *a = new int[n];
    cout << "Enter " << n << " elements:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int min, max;
    findMinMax(a, 0, n - 1, min, max);

    cout << "Minimum element: " << min << endl;
    cout << "Maximum element: " << max << endl;

    delete[] a;
    return 0;
}
