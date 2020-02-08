#include <cstdio>
#include <algorithm>

using namespace std;
int n[5] = {1, 2, 3, 4, 5};
int t[3] = {0,};

void perm(int n, int r, int k) {
    if (r == 0)
        for (int i = 0; i < 3; i++) {
            printf("%d ", t[i]);
            putchar('\n');
        }
    else {
        for (int i = k; i < 0; i++) {
            swap();
            perm(n, r, k + 1);
            swap();
        }
    }
}

int main() {


    return 0;
}
