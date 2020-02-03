#include <cstdio>
#include <vector>

using namespace std;

struct node {
    int val;
    char op;
    node *left;
    node *right;
    node(int val, char op, node *left, node *right) {
        this->val = val;
        this->op = op;
        this->left = left;
        this->right = right;
    }
};

vector<node> stack;

int calc_stack() {
    int x, y;
    vector<node> buf;
    while (true) {
        node t = *(stack.end());
        stack.pop_back();
        if (t.op == '+') {
            x = buf.end()->val;
            buf.pop_back();
            y = buf.end()->val;
            buf.pop_back();
            stack.push_back(node(x + y, 0, NULL, NULL));
        } else if (t.op == '*') {
            x = buf.end()->val;
            buf.pop_back();
            y = buf.end()->val;
            buf.pop_back();
            stack.push_back(node(x * y, 0, NULL, NULL));
        } else {
            buf.push_back(t);
        }
        if (stack.empty())
            return t.val;
    }
}

void preorder_travesal(node *root) {
    stack.push_back(*root);
    if (root->left != NULL)
        preorder_travesal(root->left);
    if (root->right != NULL)
        preorder_travesal(root->right);
}

int main() {
    node l5 = node(5, 0, NULL, NULL);
    node r5 = node(4, 0, NULL, NULL);
    node l4 = node(6, 0, NULL, NULL);
    node r4 = node(-1, '+', &l5, &r5);
    node l3 = node(-1, '*', &l4, &r4);
    node r3 = node(3, 0, NULL, NULL);
    node l2 = node(7, 0, NULL, NULL);
    node r2 = node(-1, '+', &l3, &r3);
    node root = node(-1, '+', &l2, &r2);
    preorder_travesal(&root);

    printf("Answer: %d\n", calc_stack());

    return 0;
}
