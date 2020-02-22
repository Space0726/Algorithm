#include <cstdio>

using namespace std;

unsigned int bin_search_sqrt(unsigned long long int n, unsigned int low, unsigned int high) {
    unsigned int mid = (low+high) / (unsigned int) 2;
    unsigned long long int sq = (unsigned long long int) mid*mid;
    unsigned long long int added_sq = (unsigned long long int) ++mid*mid;
    --mid;
    if (sq <= n && n < added_sq)
        return mid;
    else if (sq < n)
        return bin_search_sqrt(n, low, --mid);
    else if (n < sq)
        return bin_search_sqrt(n, ++mid, high);
}

int main() {
    unsigned long long int n;
    unsigned int ans;
    scanf("%llu", &n);
    if (n < 1)
        ans = 0;
    else if (n < 4)
        ans = 1;
    else
        ans = bin_search_sqrt(n, (unsigned int) 0, (unsigned int) 4294967295);
    printf("%u", ans);

    return 0;
}
