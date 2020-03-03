#include <iostream>

using namespace std;

struct Node {
    int val = -1;
    bool alive = false;
};

Node bintree[20];

int search_elem(int node_num, int val) {
    if (node_num >= 20)
        return -1;
    printf("!%d\n", node_num);
    if (!bintree[node_num].alive)
        return -1;
    if (bintree[node_num].val == val)
        return node_num;
    else if (bintree[node_num].val < val)
        return search_elem(node_num*2 + 1, val);
    else if (bintree[node_num*2].val > val)
        return search_elem(node_num*2, val);
}

int add_elem(int node_num, int val) {
    if (bintree[node_num].val == val)
        return -1;
    if (!bintree[node_num].alive) {
        bintree[node_num].alive = true;
        bintree[node_num].val = val;
        return node_num;
    }
    if (bintree[node_num].val < val) {
        return add_elem(node_num*2 + 1, val);
    } else if (bintree[node_num].val > val) {
        return add_elem(node_num*2, val);
    }
}

void print_tree() {
    for (int i = 1; i < 20; ++i)
        printf("%d ", bintree[i].val);
    putchar('\n');
}

void print_sorted(int node_num) {
    if (!bintree[node_num].alive)
        return;
    print_sorted(node_num*2);
    printf("%d ", bintree[node_num].val);
    print_sorted(node_num*2 + 1);
}

int main() {
    int arr[10] = {4,3,6,7,8,9,5,2,1,0};
    for (int i = 0; i < 10; ++i)
        add_elem(1, arr[i]);
    print_tree();
    print_sorted(1);
    cout << endl;
    printf("%d\n", search_elem(1, 8));
    printf("%d\n", search_elem(1, 9));
    return 0;
}
