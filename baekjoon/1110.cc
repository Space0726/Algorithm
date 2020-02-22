#include <cstdio>

using namespace std;

int main() {
    int n, c;
    int cnt = 0;
    scanf("%d", &n);
    c = n;
    do {
        ++cnt;
        if (c < 10)
            c = c*11;
        else
            c = c%10*10 + (c/10 + c%10)%10;
    } while (n != c);
    printf("%d", cnt);

    return 0;
}
