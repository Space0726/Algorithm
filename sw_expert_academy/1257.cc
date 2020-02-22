#include <iostream>
#include <set>
#include <string>

using namespace std;

int k;
set<string> strs;

int main() {
    int t, cnt;
    string tmp;
    scanf("%d", &t);
    for (int test_case = 1; test_case <= t; ++test_case) {
        cin >> k >> tmp;
        strs = set<string>();
        for (int j = 1; j <= tmp.size(); ++j)
            for (int i = 0; i < tmp.size() - j + 1; ++i)
                strs.insert(tmp.substr(i, j));
        cnt = 0;
        printf("#%d ", test_case);
        if (k > strs.size())
            printf("none\n");
        else
            for (auto it = strs.begin(); it != strs.end(); ++it)
                if (++cnt == k) {
                    cout << *it << '\n';
                    break;
                }
    }
    return 0;
}
