#include <iostream>
#include <set>

using namespace std;

struct IntCmp {
    bool operator()(const int &a, const int &b) const {
        return a > b;
    }
};

int n, k, len;
char numbers[28];
set<int, IntCmp> save;

int pow(int n_, int s) {
    if (s == 0)
        return 1;
    else if (s == 1)
        return n_;
    if (s & 1)
        return pow(n_, s / 2) * pow(n_, s / 2) * n_;
    return pow(n_, s / 2) * pow(n_, s / 2);
}

int hex2int(char *hex) {
    int ret = 0;
    for (int i = len - 1; i >= 0; --i) {
        if (hex[i] >= 'A')
            ret += pow(16, len - 1 - i) * (hex[i] - 'A' + 10);
        else
            ret += pow(16, len - 1 - i) * (hex[i] - '0');
    }
    return ret;
}

void strstr(char *from, char *to, int s, int e) {
    for (int i = s; i < e; ++i) {
        if (i >= n)
            to[i - s] = from[i % n];
        else
            to[i - s] = from[i];
    }
}

void find_numbers() {
    char buf[7];
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < 4; ++j) {
            strstr(numbers, buf, i + len*j, i + len*(j + 1));
            save.insert(hex2int(buf));
        }
    }
}

int main() {
    int T, cnt;
    scanf("%d", &T);
    for (int test_case = 1; test_case <= T; ++test_case) {
        scanf("%d%d", &n, &k);
        scanf("%s", numbers);
        save = set<int, IntCmp>();
        len = n / 4;
        cnt = 0;
        find_numbers();
        for (auto it = save.begin(); it != save.end(); ++it) {
            if (++cnt == k) {
                printf("#%d %d\n", test_case, *it);
                break;
            }
        }
    }
    return 0;
}
