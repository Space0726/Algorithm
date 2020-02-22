#include <cstdio>

using namespace std;

int main() {
    for (int test_case = 1; test_case <= 10; test_case++) {
        int len, i, paren_cnt = 0, square_cnt = 0, curly_cnt = 0, angle_cnt = 0;
        char t;
        bool ans = true;
        scanf("%d", &len);
        for (i = 0; i < len; i++) {
            scanf(" %c", &t);
            switch (t) {
                case '(':
                    ++paren_cnt;
                    break;
                case ')':
                    --paren_cnt;
                    break;
                case '[':
                    ++square_cnt;
                    break;
                case ']':
                    --square_cnt;
                    break;
                case '{':
                    ++curly_cnt;
                    break;
                case '}':
                    --curly_cnt;
                    break;
                case '<':
                    ++angle_cnt;
                    break;
                case '>':
                    --angle_cnt;
                    break;
            }
        }
        if (paren_cnt || square_cnt || curly_cnt || angle_cnt)
            ans = false;
        printf("#%d %d\n", test_case, ans);
    }

    return 0;
}
