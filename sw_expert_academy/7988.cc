#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

int K, N;
vector<vector<bool>> synergy;
vector<int> team;
unordered_map<string, int> table;
bool ans;

bool bfs(int idx) {
    int cur;
    queue<int> q;
    q.push(idx);
    while (!q.empty()) {
        cur = q.front();
        for (int i = 0; i < N; ++i) {
            if (synergy[cur][i]) {
                if (team[i]) {
                    if (team[i] == team[cur]) {
                        ans = false;
                        return false;
                    }
                    continue;
                }
                team[i] = team[cur] == 1 ? 2 : 1;
                q.push(i);
            }
        }
        q.pop();
    }
    return true;
}

int main() {
    int T;
    string t1, t2;
    scanf("%d", &T);
    for (int test_case = 1; test_case <= T; ++test_case) {
        N = 0;
        ans = true;
        scanf("%d", &K);
        synergy = vector<vector<bool>>(2*K, vector<bool>(2*K));
        table = unordered_map<string, int>();
        for (int i = 0; i < K; ++i) {
            cin >> t1 >> t2;
            if (table.find(t1) == table.end())
                table[t1] = N++;
            if (table.find(t2) == table.end())
                table[t2] = N++;
            synergy[table[t1]][table[t2]] = true;
            synergy[table[t2]][table[t1]] = true;
        }
        team = vector<int>(N);
        for (int i = 0; i < N; ++i) {
            if (!team[i]) {
                team[i] = 1;
                if (!bfs(i))
                    break;
            }
        }
        printf("#%d %s\n", test_case, ans ? "Yes" : "No");
    }
    return 0;
}
