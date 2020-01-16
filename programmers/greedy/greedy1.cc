#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> lost;
vector<int> reserve;

void input() {
    n = 5;

    int lost_in[] = {2,4};
    for (int i = 0; i < sizeof(lost_in) / sizeof(int); i++)
        lost.push_back(lost_in[i]);

    int reserve_in[] = {3};
    for (int i = 0; i < sizeof(reserve_in) / sizeof(int); i++)
        reserve.push_back(reserve_in[i]);
}

void print() {
    cout << "n: " << n << endl;

    cout << "lost: ";
    for (const auto &i: lost)
        cout << i << " ";
    cout << endl;

    cout << "reserve: ";
    for (const auto &i: reserve)
        cout << i << " ";
    cout << endl;
}

int main() {
    input();
    int rsv_idx = 0;
    int lost_idx = 0;
    int lost_size = lost.size();
    int rsv_size = reserve.size();
    int answer = n - lost_size;
    int diff;
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());

    while (rsv_idx < rsv_size && lost_idx < lost_size) {
        diff = lost[lost_idx] - reserve[rsv_idx];
        if (diff > 1) {
            rsv_idx++;
        } else if (diff < -1) {
            lost_idx++;
        } else if (diff == 1) {
            rsv_idx++;
            if (rsv_idx + 1 < rsv_idx && lost[lost_idx] == reserve[rsv_idx + 1])
                rsv_idx++;
            lost_idx++;
            answer++;
        } else if (diff == -1) {
            lost_idx++;
            if (lost_idx + 1 < lost_size && lost[lost_idx + 1] == reserve[rsv_idx])
                lost_idx++;
            rsv_idx++;
            answer++;
        } else {
            rsv_idx++;
            lost_idx++;
            answer++;
        }
    }

    cout << answer << endl;

    return 0;
}
