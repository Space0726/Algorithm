#include <cstdio>
#include <vector>
#include <cstdlib>

using namespace std;

int n, ans = 0;
vector<int> col;

// void print_vector(int x) {
    // for (int i = 0; i < n; i++) {
        // for (int j = 0; j < n; j++) {
            // if (x < i)
                // printf("0 ");
            // else {
                // if (col[i] != j)
                    // printf("0 ");
                // else
                    // printf("1 ");
            // }
        // }
        // putchar('\n');
    // }
    // putchar('\n');
// }

bool promising(int x) {
    for (int i = 0; i < x; i++)
        if (col[i] == col[x] || abs(col[i] - col[x]) == abs(x - i))
            return false;
    return true;
}

void depth_first_search(int x) {
    if (x == n) {
        ++ans;
        return;
    }
    for (int i = 0; i < n; i++) {
        col[x] = i;
        if (promising(x))
            depth_first_search(x+1);
    }
}
void path(int y) {
    bool ko;
    if (y == n) {
        ++ans;
        return;
    }
    for (int i = 0; i < n; i++) {
        ko = true;
        for (int j = 0; j < y; j++) {
            if (col[j] == i || abs(y-j) == abs(i-col[j])) {
                ko = false;
                break;
            }
        }
        if (ko) {
            col[y] = i;
            path(y+1);
        }
    }
}

int main() {
    scanf("%d", &n);
    col = vector<int>(n);//, -1);
    // depth_first_search(0);
    path(0);
    printf("%d", ans);


    return 0;
}
