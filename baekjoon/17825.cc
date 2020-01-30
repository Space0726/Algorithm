#include <cstdio>

using namespace std;

int main() {
    int num[10], i;
    for (i = 0; i < 10; i++)
        scanf(" %d", num+i);

    for (i = 0; i < 10; i++)
        printf("%d\n", *(num+i));

    return 0;
}
