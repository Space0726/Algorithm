#include <cstdio>
#include <vector>

using namespace std;

struct Node {
    int num;
    char op;
    int left;
    int right;
};
vector<Node> v;

void post_order(int k) {
    if (v[k].left)
        post_order(v[k].left);
    if (v[k].right)
        post_order(v[k].right);
    switch (v[k].op) {
    case '+':
        v[k].num = v[v[k].left].num + v[v[k].right].num;
        break;
    case '-':
        v[k].num = v[v[k].left].num - v[v[k].right].num;
        break;
    case '*':
        v[k].num = v[v[k].left].num * v[v[k].right].num;
        break;
    case '/':
        v[k].num = v[v[k].left].num / v[v[k].right].num;
        break;
    default:
        return;
    }
}

bool is_op(char *str) {
    int cnt = 0;
    for (; *str; ++str)
        if (*str == ' ' && ++cnt > 1)
            return true;
    return false;
}

int main() {
    for (int test_case = 1; test_case <= 10; ++test_case) {
        int n, tmp;
        char str[20];
        scanf("%d", &n);
        v = vector<Node>(n + 1);
        for (int i = 1; i <= n; ++i) {
            scanf(" %[^\n]", str);
            if (is_op(str)) {
                sscanf(str, "%d %c %d %d", &tmp, &v[i].op, &v[i].left, &v[i].right);
            } else {
                sscanf(str, "%d %d", &tmp, &v[i].num);
                v[i].op = 0;
                v[i].left = 0;
                v[i].right = 0;
            }
        }
        post_order(1);
        printf("#%d %d\n", test_case, v[1].num);
    }

    return 0;
}
