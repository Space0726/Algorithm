#include <iostream>
#include <cstring>

using namespace std;

struct Node {
    int child[2] = {-1, -1};
    int parent = -1;
    Node(){}
    void input_child(int num) { child[child[0] == -1 ? 0 : 1] = num; }
};

Node tree[10001];
bool check[10001];
int v, e, from, to, size, ancestor;

int travelsal(int num) {
    int ret = 0;
    check[num] = true;
    ++size;
    if (num == to)
        ret = 1;
    if (tree[num].child[0] != -1 && !check[tree[num].child[0]])
        ret |= travelsal(tree[num].child[0]);
    if (tree[num].child[1] != -1 && !check[tree[num].child[1]])
        ret |= travelsal(tree[num].child[1]);
    return ret;
}

int main() {
    int t;
    scanf("%d", &t);
    for (int test_case = 1; test_case <= t; ++test_case) {
        int a, b;
        scanf("%d%d%d%d", &v, &e, &from, &to);
        size = 1;
        memset(check, false, sizeof(check));
        for (int i = 0; i < v; ++i)
            tree[i] = Node();
        for (int i = 0; i < e; ++i) {
            scanf("%d%d", &a, &b);
            tree[a].input_child(b);
            tree[b].parent = a;
        }
        check[from] = true;
        a = from;
        for (int i = 0; i < 2; ++i)
            if (tree[a].child[i] != -1)
                travelsal(tree[a].child[i]);
        while (1) {
            if (travelsal(tree[a].parent)) {
                ancestor = tree[a].parent;
                break;
            }
            a = tree[a].parent;
        }
        printf("#%d %d %d\n", test_case, ancestor, size);
    }
    return 0;
}
