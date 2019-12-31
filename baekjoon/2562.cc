#include <cstdio>

using namespace std;

int main() {
    int n[9];
    int arg_max = 0;
    for (int i = 0; i < 9; i++) {
        scanf("%d", n+i);
        if (n[arg_max] < n[i])
            arg_max = i;
    }
    printf("%d\n%d", n[arg_max], arg_max+1);

    return 0;
}
