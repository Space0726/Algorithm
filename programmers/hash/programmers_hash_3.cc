#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    unordered_map<string, int> map;
    int cnt = -1;
    vector<int> cases;
    for (vector<string>& cloth: clothes)
        if (map.find(cloth[1]) == map.end()) {
            map[cloth[1]] = ++cnt;
            cases.push_back(1);
        } else { ++cases[map[cloth[1]]]; }
    int ans = cases[0] + 1;
    for (int i = 1; i < cases.size(); ++i)
        ans *= (cases[i] + 1);
    return ans - 1;
}
