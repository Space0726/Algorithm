#include <cstdio>
#include <vector>

using namespace std;

int bin_search_loop(vector<int> &v, int low, int high, int target) {
    while (low <= high) {
        int mid = (low + high) / 2;
        if (v[mid] == target)
            return mid;
        if (v[mid] > target)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int bin_search_recur(vector<int> &v, int low, int high, int target) {
    if (low > high)
        return -1;

    int mid = (low + high) / 2;
    if (v[mid] == target)
        return mid;
    if (v[mid] > target)
        return bin_search_recur(v, low, mid-1, target);
    return bin_search_recur(v, mid+1, high, target);
}

int main() {
    freopen("3517_input.txt", "r", stdin);
    int n, q, t;

    scanf("%d", &n);
    vector<int> ai(n);
    for (int i = 0; i < n; i++) {
        scanf(" %d", &t);
        ai[i] = t;
    }

    scanf(" %d", &q);
    vector<int> bi(q);
    for (int i = 0; i < q; i++) {
        scanf(" %d", &t);
        bi[i] = t;
    }

    for (int i = 0; i < q; i++)
        printf("%d ", bin_search_recur(ai, 0, n-1, bi[i]));

    printf("\n");

    for (int i = 0; i < q; i++)
        printf("%d ", bin_search_loop(ai, 0, n-1, bi[i]));

    return 0;
}
