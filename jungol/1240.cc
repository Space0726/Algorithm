#include <cstdio>

using namespace std;

int bin_search_sqrt(int n, int low, int high) {
    int mid = (low + high) / 2;
    int square = mid*mid;
    if (square == n)
        return mid;
    else if (square < n)
        return bin_search_sqrt(n, low, mid-1);
    else
        return bin_search_sqrt(n, mid+1, high);
}

int main() {
    int n, ans;
    scanf("%d", &n);
    if (n == 1)
        ans = 1;
    else {
        if (n == (n/2)*(n/2))
            ans = 2;
        else
            ans = bin_search_sqrt(n, 0, n/2);
    }
    printf("%d", ans);

    return 0;
}
