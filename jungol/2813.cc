#include <cstdio>

using namespace std;

int prime[2000001];

void eratos(int n) {
    int i, j;
    prime[1] = 1;
    for (i = 2; i*i <= n; i++)
        if (!prime[i])
            for (j = i*i; j <= n; j += i)
                prime[j] = 1;
}

int main() {
    int s, e;
    int cnt = 0;
    scanf("%d %d", &s, &e);
    eratos(e);
    for (int i = s; i <= e; i++)
        if (!prime[i])
            ++cnt;
    printf("%d\n", cnt);

    return 0;
}
