#include <iostream>
#include <vector>

using namespace std;

int n, m, start, ended;
vector<vector<char>> v;
int check_list[8];
char codes[10] = {
    0b0001101,
    0b0011001,
    0b0010011,
    0b0111101,
    0b0100011,
    0b0110001,
    0b0101111,
    0b0111011,
    0b0110111,
    0b0001011
};

int calc_code() {
    int sum = 0, odd = 0, even = 0;
    for (int i = 0; i < 7; ++i) {
        sum += check_list[i];
        if ((i + 1) & 1)
            odd += check_list[i];
        else
            even += check_list[i];
    }
    if ((odd*3 + even + check_list[7]) % 10)
        return 0;
    else
        return sum + check_list[7];
}

int check_codes() {
    char check = 0;
    int check_start = 0, start_idx = ended - 55;
    for (int i = start_idx; i < start_idx + 6; ++i) {
        check <<= 1;
        check |= v[start][i] - '0';
        check &= 0b01111111;
    }
    for (int i = start_idx + 6; i < m; ++i) {
        check <<= 1;
        check |= v[start][i] - '0';
        check &= 0b01111111;
        for (int j = 0; j < 10; ++j) {
            if (codes[j] == check) {
                check_list[check_start++] = j;
                if (check_start == 8)
                    return calc_code();
                for (int k = 1; k <= 6; ++k) {
                    check <<= 1;
                    check |= v[start][i + k] - '0';
                    check &= 0b01111111;
                }
                i += 6;
                break;
            }
        }
    }
}

void init() {
    scanf("%d %d", &n, &m);
    v = vector<vector<char>>(n, vector<char>(m));
    start = 0;
    ended = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf(" %c", &v[i][j]);
            if (v[i][j] == '1') {
                if (ended < j)
                    ended = j;
                if (!start)
                    start = i;
            }
        }
    }
}

int main() {
    int t;
    scanf("%d", &t);
    for (int test_case = 1; test_case <= t; ++test_case) {
        init();
        printf("#%d %d\n", test_case, check_codes());
    }
    return 0;
}
