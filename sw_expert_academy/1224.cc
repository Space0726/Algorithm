#include <iostream>
#include <string>
#include <stack>

using namespace std;

string str;
string post_order;

int calc_stack() {
    int x, y;
    stack<int> result;
    for (int i = 0; i < post_order.length(); ++i) {
        switch (post_order[i]) {
        case '+': case '*':
            y = result.top(); result.pop();
            x = result.top(); result.pop();
            if (post_order[i] == '+')
                result.push(x + y);
            else
                result.push(x * y);
            break;
        default:
            result.push(post_order[i] - 48);
            break;
        }
    }
    return result.top();
}

void fill_stack() {
    stack<char> tmp;
    for (int i = 0; i < str.length(); ++i) {
        switch (str[i]) {
        case '+':
            if (!tmp.empty())
                while (tmp.top() == '*') {
                    post_order += tmp.top();
                    tmp.pop();
                    if (tmp.empty())
                        break;
                }
        case '*': case '(':
            tmp.push(str[i]);
            break;
        case ')':
            while (tmp.top() != '(') {
                post_order += tmp.top();
                tmp.pop();
            }
            tmp.pop();
            break;
        default:
            post_order += str[i];
            break;
        }
    }
    if (!tmp.empty())
        while (tmp.empty()) {
            post_order += tmp.top();
            tmp.pop();
        }
}

int main() {
    for (int test_case = 1; test_case <= 10; ++test_case) {
        int len;
        post_order = "";
        cin >> len >> str;
        fill_stack();
        printf("#%d %d\n", test_case, calc_stack());
    }
    return 0;
}
