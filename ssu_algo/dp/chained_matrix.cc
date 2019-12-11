#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print_vector2d(vector<vector<int>> &v) {
    for (const auto &a: v) {
        for (const auto &b: a)
            cout << b << " ";
        cout << endl;
    }
}

int minmult(int n, const vector<int> d, vector<vector<int>> &P) {
    int i, j, k, diagonal, temp;
    vector<vector<int>> M(n, vector<int>(n));
    for (i = 0; i < n; i++)
        M[i][i] = 0;
    print_vector2d(M);
    for (diagonal = 0; diagonal < n-1; diagonal++) {
        for (i = 0; i < n-diagonal; i++) {
            j = i + diagonal;
            int min_ = 0xFFFFFF;
            for (k = i; k < j; k++) {
                cout << M[i][k] << " ";
                cout << M[k+1][j] << " ";
                cout << d[i]*d[k+1]*d[j+1] << endl;
                min_ = min(min_, M[i][k] + M[k+1][j] + d[i]*d[k+1]*d[j+1]);
                temp = k;
            }
            M[i][j] = min_;
            P[i][j] = temp;
        }
    }

    print_vector2d(M);
    return M[0][n-1];
}

void order(int i, int j, vector<vector<int>> &P) {
    if (i == j)
        cout << "A" << i+1;
    else {
        int k = P[i][j];
        cout << "(";
        order(i, k, P);
        order(k+1, j, P);
        cout << ")";
    }
}

void print_vector(vector<int> &v) {
    for (const auto &a: v)
        cout << a;
    cout << endl;
}

int main() {
    int n;
    cout << "Type n: ";
    cin >> n;
    vector<int> d(n+1);
    vector<vector<int>> P(n, vector<int>(n));

    cout << "Type d:" << endl;
    for (int i = 0; i < n+1; i++)
        cin >> d[i];

    cout << minmult(n, d, P) << endl;
    order(0, n-1, P);
    cout << endl;

    return 0;
}
