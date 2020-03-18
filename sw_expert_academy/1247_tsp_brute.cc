#include <iostream>

using namespace std;

int n, w_x, w_y, h_x, h_y, cli_x[10], cli_y[10], min_dist, arr[10];

int abs(int val) { return val < 0 ? -val : val; }

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int dist(int x, int y, int other_x, int other_y) {
    return abs(x - other_x) + abs(y - other_y);
}

void fact(int n_) {
    if (n_ == 0) {
        int distance = dist(w_x, w_y, cli_x[arr[0]], cli_y[arr[0]])
                       + dist(cli_x[arr[n-1]], cli_y[arr[n-1]], h_x, h_y);
        for (int i = 0; i < n - 1; ++i)
            distance += dist(cli_x[arr[i]], cli_y[arr[i]], cli_x[arr[i+1]], cli_y[arr[i+1]]);
        min_dist = distance < min_dist ? distance : min_dist;
    } else {
        for (int i = n_ - 1; i >= 0; --i) {
            swap(arr + n_ - 1, arr + i);
            fact(n_ - 1);
            swap(arr + n_ - 1, arr + i);
        }
    }
}

int main() {
    int t;
    scanf("%d", &t);
    for (int test_case = 1; test_case <= t; ++test_case) {
        min_dist = 1e4;
        scanf("%d%d%d%d%d", &n, &w_x, &w_y, &h_x, &h_y);
        for (int i = 0; i < n; ++i) {
            scanf("%d%d", cli_x + i, cli_y + i);
            arr[i] = i;
        }
        fact(n);
        printf("#%d %d\n", test_case, min_dist);
    }
    return 0;
}
