#include <cstdio>

using namespace std;

int main() {
    int A, B, C, digit;
    scanf("%d %d %d", &A, &B, &C);
    int mul = A*B*C;
    char cnt[10] = {0,};
    for (digit = 1; digit <= mul; digit *= 10)
        cnt[mul/digit%10]++;
    for (digit = 0; digit < 10; digit++)
        printf("%d\n", cnt[digit]);

    return 0;
}
