#include <iostream>
#include <map>
#include <string>

using namespace std;

map<string, int> m {
    {"ZRO", 0},
    {"ONE", 1},
    {"TWO", 2},
    {"THR", 3},
    {"FOR", 4},
    {"FIV", 5},
    {"SIX", 6},
    {"SVN", 7},
    {"EGT", 8},
    {"NIN", 9},
};

int num_cnt[10];
string numbers[10] = {"ZRO", "ONE", "TWO", "THR", "FOR", "FIV", "SIX", "SVN", "EGT", "NIN"};

int main() {
    int t, t_len;
    string test_case, tmp;
    scanf("%d", &t);
    while (t--) {
        cin >> test_case >> t_len;
        for (int i = 0; i < 10; ++i)
            num_cnt[i] = 0;
        for (int i = 0; i < t_len; ++i) {
            cin >> tmp;
            ++num_cnt[m[tmp]];
        }
        cout << test_case << '\n';
        for (int i = 0; i < 10; ++i)
            for (int j = 0; j < num_cnt[i]; ++j)
                cout << numbers[i] << " ";
        putchar('\n');
    }
    return 0;
}
