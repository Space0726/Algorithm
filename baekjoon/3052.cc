#include <cstdio>

using namespace std;

int main() {
    int n, i;
    bool remainers[42] = {0,};
    for (i = 0; i < 10; i++) {
        scanf("%d", &n);
        remainers[n%42] = true;
    }
    int cnt = 0;
    for (i = 0; i < 42; i++)
        if (remainers[i])
            ++cnt;
    printf("%d", cnt);

    return 0;
}
