// 원형 문자열의 모든 시작 점에서의 문자열 중
// 사전순으로 가장 앞에 오는 문자열 찾기
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string min_shift(const string& s) {
    string s2 = s + s;  // 같은 문자열을 뒤에 하나 더 붙여 원형 계산
    vector<int> a = get_suffix_array(s2);
    for (int i = 0; i < a.size(); ++i)
        if (a[i] <= s.size())
            return s2.substr(a[i], s.size());
    return "__error__";
}

int main() {
    return 0;
}
