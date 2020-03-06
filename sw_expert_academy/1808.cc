#include <iostream>

using namespace std;

int min_, num;
bool number[10];

int check(int n) {
    char tmp[8];
    int len = sprintf(tmp, "%d", n);
    for (int i = 0; i < len; ++i)
        if (!number[tmp[i] - '0'])
            return 0;
    return len;
}

void dfs(int cnt, int n) {
    if (cnt > min_) return;
    int result = check(n);
    if (result) {
        min_ = min_ > result + cnt ? result + cnt : min_;
    } else {
        for (int i = 9; i > 1; --i) {
            if (number[i] && n % i == 0) {
                n /= i;
                cout << "N: " << n << endl;
                dfs(cnt + 1, n);
                n *= i;
            }
        }
    }
}

int main() {
    freopen("input_1808.txt", "r", stdin);
    int T, len;
    scanf("%d", &T);
    for (int test_case = 1; test_case <= 5; ++test_case) {
        min_ = 2e9;
        for (int i = 0; i < 10; ++i)
            scanf("%d", number + i);
        scanf("%d", &num);
        cout << "Number: " << num << endl;
        for (int i = 0; i < 10; ++i) {
            if (number[i])
                printf("%d ", i);
        }
        putchar('\n');
        dfs(1, num);
        printf("#%d %d\n", test_case, min_ == 2e9 ? -1 : min_);
    }
    return 0;
}
