#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    unordered_map<string, vector<pair<int, int>>> map;
    for (int i = 0; i < genres.size(); ++i)
        if (map.find(genres[i]) == map.end())
            map[genres[i]] = {{i, plays[i]}};
        else
            map[genres[i]].push_back({i, plays[i]});

    vector<pair<string, int>> cnt;
    for (auto& psv: map) {
        int sum = 0;
        for (auto& pii: psv.second)
            sum += pii.second;
        cnt.push_back({psv.first, sum});
    }
    sort(cnt.begin(), cnt.end(),
            [](pair<string, int>& a, pair<string, int>& b) { return a.second > b.second; });

    vector<int> answer;
    for (auto& psi: cnt) {
        if (map[psi.first].size() == 1) {
            answer.push_back(map[psi.first][0].first);
            continue;
        }
        sort(map[psi.first].begin(), map[psi.first].end(),
                [](pair<int, int>& a, pair<int, int>& b) {
                    if (a.second == b.second) return a.first < b.first;
                    return a.second > b.second;
                });
        for (int i = 0; i < 2; ++i)
            answer.push_back(map[psi.first][i].first);
    }
    return answer;
}
