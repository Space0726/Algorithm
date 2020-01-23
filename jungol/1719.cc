#include <cstdio>

using namespace std;

int main() {
    int n, m, i, j;
    scanf("%d %d", &n, &m);
    if (n > 100 || !(n&1) || m < 1 || m > 4)
        printf("INPUT ERROR!");
    else {
        switch(m) {
        case 1:
            for (i = 0; i < n; i++) {
                for (j = 0; j < n; j++) {
                    if (i >= (n/2 >= j ? n : n-j))
                        putchar('*');
                    else
                        putchar(' ');
                }
                putchar('\n');
            }
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        }
    }

    return 0;
}
