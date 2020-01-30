#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t, tc;
    cin >> t;
    for (tc = 1; tc <= t; tc++) {
        int num, i, j, max_h, ans = 0;
        int idx[3] = {-1, 1, 2};
        cin >> num;
        vector<int> v(num);
        for (i = 0; i < num; i++)
            cin >> v[i];
        for (i = 2; i < num-2; i++) {
            max_h = v[i-2];
            for (j = 0; j < 3; j++)
                if (max_h < v[i+idx[j]])
                    max_h = v[i+idx[j]];
            if (max_h < v[i])
                ans += v[i] - max_h;
        }
        cout << "#" << tc << " " << ans << endl;
    }

    return 0;
}
