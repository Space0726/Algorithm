#include <cstdio>

using namespace std;

int main() {
    int a, b, c;
    long long mul;
    char byte[10] = {0,};
    scanf("%d %d %d", &a, &b, &c);
    mul = a*b*c;
    long long decimal = 10;
    while (mul*10 >= decimal) {
        ++byte[mul%decimal/(decimal/10)];
        decimal *= 10;
    }
    for (int i = 0; i < 10; i++)
        printf("%d\n", byte[i]);

    return 0;
}
