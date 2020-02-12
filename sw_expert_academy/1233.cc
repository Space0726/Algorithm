#include <cstdio>

using namespace std;

bool is_op(char *str) {
    int cnt = 0;
    for (; *str; ++str)
        if (*str == ' ' && ++cnt > 1)
            return true;
    return false;
}

bool check_op(char *str) {
    bool op_loc = false;
    for (; *str; ++str) {
        if (op_loc) {
            if (*str == '+' || *str == '-' || *str == '*' || *str == '/')
                return true;
            else
                return false;
        } else if (*str == ' ') {
            op_loc = true;
        }
    }
    return false;
}

bool check_num(char *str) {
    bool num_loc = false;
    for (; *str; ++str) {
        if (num_loc) {
            if ('0' <= *str && *str <= '9')
                return true;
            else
                return false;
        } else if (*str == ' ') {
            num_loc = true;
        }
    }
    return false;
}

int main() {
    for (int test_case = 1; test_case <= 10; ++test_case) {
        int n, tmp, ans = 1;
        char str[20], ch;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf(" %[^\n]", str);
            if (ans && (is_op(str) && !check_op(str)) || (!is_op(str) && !check_num(str)))
                ans = 0;
        }
        printf("#%d %d\n", test_case, ans);
    }
    return 0;
}
