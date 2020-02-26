#include <iostream>

using namespace std;

int arr[5] = {1, 2, 3, 4, 5};
int n = 5, r = 3;

void swap(int a, int b) {
    int t = arr[a];
    arr[a] = arr[b];
    arr[b] = t;
}

void perm(int k) {
    if (k == r) {
        for (int i = 0; i < r; ++i)
            cout << arr[i] << " ";
        cout << endl;
    } else {
        for (int i = k; i < n; ++i) {
            swap(k, i);
            perm(k + 1);
            swap(k, i);
        }
    }
}

void comb(int k, int s) {
    if (k == r) {
        for (int i = 0; i < r; ++i)
            cout << arr[i] << " ";
        cout << endl;
    } else {
        for (int i = s; i <= n + (k - r); ++i) {
            swap(k, i);
            comb(k + 1, i + 1);
            swap(k, i);
        }
    }
}

int main() {
    cout << "Perm: " << endl;
    perm(0);
    cout << "Comb: " << endl;
    comb(0, 0);
    return 0;
}
