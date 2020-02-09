#include <cstdio>
#include <vector>

using namespace std;

union NodeValue {
    int number;
    char ch;
};

struct Node {
    int num;
    bool is_ch;
    NodeValue val;
    int left;
    int right;
};

int result;
vector<Node> v;

void operate(int idx) {
    if (v[idx].is_ch) {
        operate(v[idx].left-1);
        operate(v[idx].right-1);
    } else
        return;
}

int main(int argc, char **argv) {
    freopen("input_1232.txt", "r", stdin);
    for (int test_case = 1; test_case <= 2; ++test_case) {
        int n, i, t;
        Node tmp;
        scanf("%d", &n);
        v = vector<Node>(n);
        result = 0;
        for (i = 0; i < n; ++i) {
            if (i < n/2) {
                tmp.is_ch = true;
                scanf("%d %c %d %d", &tmp.num, &tmp.val.ch, &tmp.left, &tmp.right);
            } else {
                tmp.is_ch = false;
                scanf("%d %d", &tmp.num, &tmp.val.number);
                tmp.left = tmp.right = -1;
            }
            v[i] = tmp;
        }
        printf("#%d ", test_case);
        operate(0);
    }

    return 0;
}
