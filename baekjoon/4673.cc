#include <cstdio>

using namespace std;

int d(int n) {
    int ret = n;
    int decimal = 1;
    while (n*10 >= decimal) {
        ret += n/decimal%10;
        decimal *= 10;
    }
    return ret;
}

int main() {
    int n, i;
    bool self[10036] = {false,};
    for (i = 1; i < 10001; i++)
        self[d(i)] = true;
    for (i = 1; i < 10001; i++)
        if (!self[i])
            printf("%d\n", i);

    return 0;
}
