#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N, temp, mean, mode = 0, min_, max_ = 0;
    bool is_second = false;
    cin >> N;
    vector<int> v(N), v2(8001, 0);
    for(int i = 0; i < N; i++) {
        cin >> v[i];
        mean += v[i];
        temp = v[i] <= 0 ? abs(v[i]) : v[i] + 4000;
        ++v2[temp];
        if(v2[temp] > max_) max_ = v2[temp];
    }
    sort(v.begin(), v.end());

    for(int i = -4000; i < 4001; i++) {
        temp = i <= 0 ? abs(i) : i + 4000;
        if(v2[temp] == max_) {
            mode = i;
            if(is_second) break;
            is_second = true;
        }
    }

    cout << round(mean/(double)N) << '\n' << v[round(N/2)] << '\n' << mode << '\n' << v[v.size() - 1] - v[0] << '\n';
}
