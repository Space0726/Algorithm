#include <cstdio>

using namespace std;

int main() {
    int num = 666, n, comp;
    int cnt = 0;
    scanf("%d", &n);
    while (cnt != n) {
        for (comp = 1000; comp < num*10; comp *= 10)
            if (num%comp/(comp/1000) == 666) {
                ++cnt;
                break;
            }
        if (cnt == n)
            break;
        ++num;
    }
    printf("%d\n", num);

    return 0;
}
