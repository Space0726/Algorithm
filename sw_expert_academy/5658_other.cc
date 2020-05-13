#include <iostream>
#include <string>
#include <set>

using namespace std;

int N, K, ans;
string strs;

void find() {
    int len = N / 4;
    set<int> s;
    for (int i = 0; i < len; ++i)
        for (int j = 0; j < 4; ++j) {
            string tmp = strs.substr(N + j*len - i, len);
            int t;
            sscanf(tmp.c_str(), "%x", &t);
            s.insert(t);
        }
    int cnt = 0;
    for (auto it = s.end(); it != s.begin(); --it)
        if (++cnt == K+1) { ans = *it; break; }
    if (++cnt == K+1) ans = *s.begin();
}

int main() {
    int T;
    scanf("%d", &T);
    for (int test_case = 1; test_case <= T; ++test_case) {
        cin >> N >> K;
        cin >> strs;
        strs += strs;
        find();
        printf("#%d %d\n", test_case, ans);
    }
    return 0;
}
