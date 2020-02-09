#include <iostream>
#include <stack>
#include <string>

using namespace std;

int n;
string str, new_str;

void post_order() {
    stack<char> tmp;
    for (int i = 0; i < n; i++) {
        if (48 <= str[i] && str[i] <= 57)
            new_str += str[i];
        else {
            if (str[i] == '(') {
                tmp.push(str[i]);
            } else if (str[i] == '+') {
                if (tmp.empty()) {
                    tmp.push(str[i]);
                    continue;
                }
                if (tmp.top() == '+' || tmp.top() == '*') {
                    while (tmp.top() == '+' || tmp.top() == '*') {
                        new_str += tmp.top();
                        tmp.pop();
                        if (tmp.empty())
                            break;
                    }
                }
                tmp.push(str[i]);
            } else if (str[i] == '*') {
                if (tmp.empty()) {
                    tmp.push(str[i]);
                    continue;
                }
                if (tmp.top() == '*') {
                    while (tmp.top() == '*') {
                        new_str += tmp.top();
                        tmp.pop();
                        if (tmp.empty())
                            break;
                    }
                }
                tmp.push(str[i]);
            } else if (str[i] == ')') {
                while (tmp.top() != '(') {
                    new_str += tmp.top();
                    tmp.pop();
                    if (tmp.empty())
                        break;
                }
                tmp.pop();
            }
        }
    }
    while (!tmp.empty()) {
        new_str += tmp.top();
        tmp.pop();
    }
}

int operate() {
    int x, y;
    stack<int> st;
    for (int i = 0; i < new_str.length(); ++i) {
        switch (new_str[i]) {
        case '+':
            x = st.top(); st.pop();
            y = st.top(); st.pop();
            st.push(x + y);
            break;
        case '*':
            x = st.top(); st.pop();
            y = st.top(); st.pop();
            st.push(x * y);
            break;
        default:
            st.push(new_str[i] - 48);
            break;
        }
    }
    return st.top();
}


int main() {
    freopen("input_1224.txt", "r", stdin);
    for (int test_case = 1; test_case <= 10; ++test_case) {
        cin >> n;
        cin >> str;
        new_str = "";
        post_order();
        printf("#%d %d\n", test_case, operate());
    }
    return 0;
}
