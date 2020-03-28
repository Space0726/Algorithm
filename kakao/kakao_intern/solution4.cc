#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<long long, long long> m;

long long update(long long number) {
    if (m.find(number) != m.end())
        return m[number] = update(m[number]);
    return number;
}

long long push(long long number) {
    long long ret;
    if (m.find(number) == m.end()) {
        ret = number;
        m[number] = update(number + 1);
    } else {
        ret = update(number);
        m[ret] = update(ret + 1);
    }
    return ret;
}

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
    for (auto &i: room_number)
        answer.push_back(push(i));
    return answer;
}
