#include <iostream>
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
    if (v[k].op != '\0') {
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
            cout << k << ", ";
            cout << v[v[k].left].num << ", " << v[v[k].right].num << endl;
            v[k].num = v[v[k].left].num / v[v[k].right].num;
            break;
        }
    }
}

int main() {
    freopen("input_1232.txt", "r", stdin);
    for (int test_case = 1; test_case <= 10; ++test_case) {
        int n, tmp;
        cin >> n;
        v = vector<Node>(n + 1);
        for (int i = 0; i < n; ++i) {
            cin >> tmp;
            if (i < n/2) {
                cin >> v[tmp].op >> v[tmp].left >> v[tmp].right;
            } else {
                cin >> v[tmp].num;
                v[tmp].op = '\0';
                v[tmp].left = 0;
                v[tmp].right = 0;
            }
        }
        post_order(1);
        printf("#%d %d\n", test_case, v[1].num);
    }

    return 0;
}
