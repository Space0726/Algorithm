#include <cstdio>

using namespace std;

char number[7];
int len, change_cnt, max_num;

int strlen(char *s) {
    int cnt = 0;
    for (; *s; ++s)
        ++cnt;
    return cnt;
}

int pow(int n, int s) {
    if (s == 0)
        return 1;
    else if (s == 1)
        return n;
    if (s & 1)
        return pow(n, s / 2) * pow(n, s / 2) * n;
    return pow(n, s / 2) * pow(n, s / 2);
}

int stoi(char *str) {
    int ret = 0;
    for (int i = 1; i <= len; ++i)
        ret += (str[i - 1] - '0') * pow(10, len - i);
    return ret;
}

void swap(char *a, char *b) {
    char t = *a;
    *a = *b;
    *b = t;
}

int perm(int n, int cnt) {
    if (cnt == change_cnt) {
        int num = stoi(number);
        if (max_num < num)
            max_num = num;
    } else {
        for (int i = n; i < len; ++i) {
            for (int j = i + 1; j < len; ++j) {
                if (number[i] <= number[j]) {
                    swap(number + i, number + j);
                    perm(i, cnt + 1);
                    swap(number + i, number + j);
                }
            }
        }
    }
}

int main() {
    int t;
    scanf("%d", &t);
    for (int test_case = 1; test_case <= t; ++test_case) {
        scanf(" %s%d", number, &change_cnt);
        len = strlen(number);
        max_num = 0;
        perm(0, 0);
        printf("#%d %d\n", test_case, max_num);
    }
    return 0;
}
