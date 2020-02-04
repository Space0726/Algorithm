#include <cstdio>
#include <vector>
#include <string>

using namespace std;

vector<string> stack;

int calc_stack() {
    int ret;
    vector<string> buf;
    string ele, x, y;

    while (stack.empty()) {
        ele = *stack.end();
        stack.pop_back();
        if (ele[0] == '+') {
            x = *buf.end();
            buf.pop_back();
            y = *buf.end();
            buf.pop_back();
            stack.push_back(to_string(atoi(x.c_str()) + atoi(y.c_str())));
        } else if (ele[0] == '*') {
            x = *buf.end();
            buf.pop_back();
            y = *buf.end();
            buf.pop_back();
            stack.push_back(to_string(atoi(x.c_str()) * atoi(y.c_str())));
        } else {
            buf.push_back(ele);
        }
    }

    return ret;
}

void fill_stack(string str) {
    for (int i = 0; i < str.length; i++) {
        if (str[i] == '(') {
            ;
        }
        else if (str[i] == ')') {
            ;
        }
        else if (str[i] == '+' || str[i] == '*') {
            ;
        }
        else {
            ;
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    for (int test_case = 1; test_case <= 10; ++test_case) {
        int len, i, j;
        string str;
        scanf("%d", &len);
        scanf(" %s", str);
        fill_stack(str);
        printf("#%d %d\n", test_case, calc_stack());
    }
    return 0;
}
