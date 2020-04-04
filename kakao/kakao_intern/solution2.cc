#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<string>> parse(string s) {
    vector<vector<string>> ret;
    vector<string> t;
    string tmp;
    bool pushed = false;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '{') {
            pushed = true;
            tmp = "";
            t = vector<string>();
            continue;
        } else if (s[i] == '}') {
            t.push_back(tmp);
            ret.push_back(t);
            pushed = false;
        }
        if (pushed) {
            if (s[i] == ',') {
                t.push_back(tmp);
                tmp = "";
            } else
                tmp += s[i];
        }
    }
    return ret;
}

bool is_inside(vector<int> &v, int a) {
    for (int &i: v)
        if (i == a) return true;
    return false;
}

vector<int> solution(string s) {
    vector<int> answer;
    vector<vector<string>> vvs = parse(s.substr(1, s.size() - 2));
    sort(vvs.begin(), vvs.end(),
         [](const vector<string> &a, const vector<string> &b) { return a.size() < b.size(); });
    for (auto &a: vvs) {
        for (auto &b: a) {
            int tmp = stoi(b);
            if (!is_inside(answer, tmp))
                answer.push_back(tmp);
        }
    }
    return answer;
}
