#include <iostream>

using namespace std;

int N, M, len[10000];

long long binary_search(long long high) {
    long long low, mid, child;
    long long ret = -1;
    while (low <= high) {
        mid = (low + high) / 2;
        child = M;
        for (int i = 0; i < M; ++i)
            child += mid / len[i];
        if (child >= N) {
            ret = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ret;
}

int main() {
    scanf("%d%d", &N, &M);
    long long t = -1;
    for (int i = 0; i < M; ++i) {
        scanf("%d", len + i);
        if (t < len[i])
            t = len[i];
    }
    if (N <= M) {
        printf("%d", N);
        return 0;
    }
    long long child = M, k = binary_search(t * N);
    for (int i = 0; i < M; ++i)
        child += (k - 1) / len[i];
    for (int i = 0; i < M; ++i) {
        if (!(k % len[i]))
            ++child;
        if (child == N) {
            printf("%d", i + 1);
            break;
        }
    }
    return 0;
}
