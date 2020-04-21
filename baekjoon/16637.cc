#include <iostream>
#include <vector>

using namespace std;

int n, max_result;
vector<int> num;
vector<char> op;
vector<bool> op_check;

void calc_result() {
    vector<int> cp_num = num;
    vector<char> cp_op = op;
    for (int i = 0; i < n / 2; ++i) {
        if (op_check[i]) {
            switch (cp_op[i]) {
                case '+':
                    cp_num[i] += cp_num[i + 1];
                    break;
                case '-':
                    cp_num[i] -= cp_num[i + 1];
                    break;
                case '*':
                    cp_num[i] *= cp_num[i + 1];
                    break;
            }
            cp_op[i] = 0;
        }
    }
    int sum = cp_num[0];
    for (int i = 0; i < n / 2; ++i) {
        switch (cp_op[i]) {
            case '+':
                sum += cp_num[i + 1];
                break;
            case '-':
                sum -= cp_num[i + 1];
                break;
            case '*':
                sum *= cp_num[i + 1];
                break;
            default:
                break;
        }
    }
    if (max_result < sum)
        max_result = sum;
}

void subset(int k) {
    if (k >= n / 2) {
        calc_result();
        return;
    }
    op_check[k] = true;
    subset(k + 2);
    op_check[k] = false;
    subset(k + 1);
}

int main() {
    scanf("%d", &n);
    num = vector<int>(n/2 + 1);
    op = vector<char>(n/2);
    op_check = vector<bool>(n/2);
    for (int i = 0; i < n; ++i) {
        if (i & 1)
            scanf("%c", &op[i/2]);
        else
            scanf("%d", &num[i/2]);
    }
    max_result = -2e9;
    subset(0);
    printf("%d", max_result);
    return 0;
}
