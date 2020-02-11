#include <cstdio>
#include <cstring>

int v;
int tree[14][2];

void pre_order(int k) {
    printf("%d ", k);
    if (tree[k][0])
        pre_order(tree[k][0]);
    if (tree[k][1])
        pre_order(tree[k][1]);
}
void in_order(int k) {
    if (tree[k][0])
        in_order(tree[k][0]);
    printf("%d ", k);
    if (tree[k][1])
        in_order(tree[k][1]);
}
void post_order(int k) {
    if (tree[k][0])
        post_order(tree[k][0]);
    if (tree[k][1])
        post_order(tree[k][1]);
    printf("%d ", k);
}

void init() {
    v = 13;
    memset(tree, 0, sizeof(tree));
    tree[1][0] = 2;
    tree[1][1] = 3;
    tree[2][0] = 4;
    tree[3][0] = 5;
    tree[3][1] = 6;
    tree[4][0] = 7;
    tree[5][0] = 8;
    tree[5][1] = 9;
    tree[6][0] = 10;
    tree[6][1] = 11;
    tree[7][0] = 12;
    tree[11][0] = 13;
}

int main() {
    init();
    printf("Pre-order Traversal:\n");
    pre_order(1);
    printf("\n\nIn-order Traversal:\n");
    in_order(1);
    printf("\n\nPost-order Traversal:\n");
    post_order(1);

    return 0;
}
