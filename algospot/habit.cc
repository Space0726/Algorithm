#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;


int C, K;
string s;

struct Comparator {
    const vector<int>& group;
    int t;
    Comparator(const vector<int>& _group, int _t): group(_group), t(_t) {}
    bool operator()(int a, int b) {
        if (group[a] != group[b]) return group[a] < group[b];
        return group[a + t] < group[b + t];
    }
};

vector<int> ManberMyers() {
    int n = s.size();
    int t = 1;
    vector<int> group(n+1);
    for (int i = 0; i < n; ++i) group[i] = s[i];
    group[n] = -1;
    vector<int> perm(n);
    for (int i = 0; i < n; ++i) perm[i] = i;
    while (t < n) {
        Comparator compareUsing2T(group, t);
        sort(perm.begin(), perm.end(), compareUsing2T);
        t *= 2;
        if (t >= n) break;
        vector<int> new_group(n+1);
        new_group[n] = -1;
        new_group[perm[0]] = 0;
        for (int i = 1; i < n; ++i)
            if (compareUsing2T(perm[i-1], perm[i]))
                new_group[perm[i]] = new_group[perm[i-1]] + 1;
            else
                new_group[perm[i]] = new_group[perm[i-1]];
        group = new_group;
    }
    return perm;
}

int common_prefix(int a, int b) {
    int k = 0;
    while (a < s.size() && b < s.size() && s[a] == s[b]) {
        ++a; ++b; ++k;
    }
    return k;
}

int find_habit() {
    int max_len = 0;
    vector<int> sufarr = ManberMyers();
    for (int i = 0; i + K <= s.size(); ++i)
        max_len = max(max_len, common_prefix(sufarr[i], sufarr[i+K-1]));
    return max_len;
}

int main() {
    scanf("%d", &C);
    for (int i = 0; i < C; ++i) {
        scanf("%d", &K);
        cin >> s;
        printf("%d\n", find_habit());
    }
    return 0;
}
