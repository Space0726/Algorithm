// 모든 부분 문자열 중 중복되지 않는 문자열의 수
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 인접한 두 문자열의 공통 접두사 최대 길이 계산
int common_prefix(const string& s, int i, int j) {
    int k = 0;
    while (i < s.size() && j < s.size() && s[i] == s[j]) {
        ++i; ++j; ++k;
    }
    return k;
}

int count_substr(const string& s) {
    vector<int> a = get_suffix_array(s);
    int ret = 0;
    int n = s.size();
    for (int i = 0; i < a.size(); ++i) {
        int cp = 0;
        if (i > 0) cp = common_prefix(s, a[i-1], a[i]);
        ret += s.size() - a[i] - cp;
    }
    return ret;
}

int main() {
    return 0;
}
