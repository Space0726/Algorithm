#include <cstdio>

using namespace std;

int main() {
    int n, sum = 0;
    scanf("%d ", &n);
    for (int i = 0; i < n; i++) 
        sum += getchar() - 48;
    printf("%d", sum);

    return 0;
}
