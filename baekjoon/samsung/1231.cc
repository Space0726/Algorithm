#include <cstdio>
#include <vector>

using namespace std;

struct Node {
    int num;
    char ch;
    int left;
    int right;
};

vector<Node> v;

void in_order(int idx) {
    if (v[idx].left != -1)
        in_order(v[idx].left-1);
    putchar(v[idx].ch);
    if (v[idx].right != -1)
        in_order(v[idx].right-1);
}

int main() {
    for (int test_case = 1; test_case <= 10; ++test_case) {
        int n, i;
        Node tmp;
        scanf("%d", &n);
        v = vector<Node>(n);
        for (i = 0; i < n; ++i) {
            scanf(" %d %c", &tmp.num, &tmp.ch);
            if (getchar() == ' ') {
                scanf("%d", &tmp.left);
                if (getchar() == ' ')
                    scanf("%d", &tmp.right);
                else
                    tmp.right = -1;
            } else {
                tmp.left = -1;
                tmp.right = -1;
            }
            v[tmp.num-1] = tmp;
        }
        printf("#%d ", test_case);
        in_order(0);
        putchar('\n');
    }

    return 0;
}
