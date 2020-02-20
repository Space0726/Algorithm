#include <cstdio>

using namespace std;

char number[7];
int num_len, change_cnt;

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

int greedy() {
    int max_t, cnt = 0, ret = 0;
    char t;
    for (int i = 0; i < num_len; ++i) {
        max_t = i;
        for (int j = i + 1; j < num_len; ++j)
            if (number[max_t] <= number[j])
                max_t = j;
        if (i == max_t) {
            continue;
        } else {
            t = number[i];
            number[i] = number[max_t];
            number[max_t] = t;
            printf("changed: %s\n", number);
            if (++cnt == change_cnt)
                break;
        }
    }
    for (int i = 1; i <= num_len; ++i)
        ret += (number[i - 1] - '0') * pow(10, num_len - i);
    return ret;
}

int main() {
    freopen("input_1244.txt", "r", stdin);
    int t;
    scanf("%d", &t);
    for (int test_case = 1; test_case <= t; ++test_case) {
        scanf(" %s%d", number, &change_cnt);
        num_len = strlen(number);
        // printf("%s\n", number);
        printf("#%d %d\n", test_case, greedy());
    }
    return 0;
}
