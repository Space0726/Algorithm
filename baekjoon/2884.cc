#include <cstdio>

using namespace std;

int main() {
    int h, m;
    scanf("%d %d", &h, &m);
    if (m < 45)
        printf("%d %d", h ? h-1 : 23, 60-(45-m));
    else
        printf("%d %d", h, m-45);

    return 0;
}
