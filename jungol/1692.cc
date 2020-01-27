#include <cstdio>

using namespace std;

int main() {
    int n1, n2, digit;
    scanf("%d %d", &n1, &n2);
    for (digit = 1; digit < n2; digit *= 10)
        printf("%d\n", n1*(n2/digit%10));
    printf("%d\n", n1*n2);

    return 0;
}
