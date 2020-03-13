#include <stdio.h>

int pow(int base, int exp) {
    if (exp == 1)
        return base;
    else if (exp == 0)
        return 1;
    int new_base = pow(base, exp/2);
    if (exp&1)
        return new_base * new_base * base;
    else
        return new_base * new_base;
}

int main() {
    int base, exp;
    scanf("%d %d", &base, &exp);
    printf("%d\n", pow(base, exp));
    return 0;
}
