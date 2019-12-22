#include <cstdio>

using namespace std;

void move_plate(int n, int from, int to) {
    if (n < 1)
        return;
    move_plate(n-1, from, 6-from-to);
    printf("%d %d\n", from, to);
    move_plate(n-1, 6-from-to, to);
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d\n", (1<<n) - 1);
    move_plate(n, 1, 3);

    return 0;
}
