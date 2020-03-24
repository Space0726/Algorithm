#include <iostream>

#define MAX(X, Y) (X > Y ? X : Y)

using namespace std;

int N;

int main() {
    int a, b, max_val;
    scanf("%d%d", &N, &a);
    max_val = a;
    for (int i = 1; i < N; ++i) {
        scanf("%d", &b);
        a = MAX(0, a) + b;
        if (max_val < a) max_val = a;
    }
    printf("%d", max_val);
    return 0;
}
