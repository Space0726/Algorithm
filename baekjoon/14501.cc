#include <cstdio>
#include <vector>

using namespace std;

int n, max_profit = -1;
vector<pair<int, int>> v;
vector<bool> tmp;

void subset(int k) {
    if (k == n) {
        int cnt = -1, sum = -1, time = -1, profit = -1;
        bool check = true;
        for (int i = 0; i < n; ++i) {
            if (tmp[i]) {
                if (check) {
                    cnt = 1;
                    time = v[i].first;
                    profit = v[i].second;
                    sum = v[i].second;
                    check = false;
                }
                else if (cnt > time) {
                    cnt = 1;
                    time = v[i].first;
                    profit = v[i].second;
                    sum += v[i].second;
                }
                else if (cnt <= time) {
                    return;
                }
            }
            ++cnt;
        }
        if (time >= cnt)
            sum -= profit;
        if (max_profit < sum)
            max_profit = sum;
    }
    else {
        tmp[k] = false;
        subset(k + 1);
        tmp[k] = true;
        subset(k + 1);
    }
}

int main() {
    int x, y;
    scanf("%d", &n);
    v = vector<pair<int, int>>();
    tmp = vector<bool>(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &x, &y);
        v.push_back(make_pair(x, y));
    }
    subset(0);
    printf("%d\n", max_profit);
    return 0;
}
