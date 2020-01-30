#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main() {
    freopen("1210_input.txt", "r", stdin);
    for (int t = 0; t < 10; t++) {
        int test_case, i, j, ans;
        cin >> test_case;
        vector<vector<int>> v(100, vector<int>(100));
        for (i = 0; i < 100; i++) {
            for (j = 0; j < 100; j++) {
                cin >> v[i][j];
                if (v[i][j] == 2)
                    ans = j;
            }
        }
        for (i = 99; i >= 0; i--) {
            if (ans > 0 && v[i][ans-1]) {
                while (v[i][--ans]);
                ++ans;
            } else if (ans < 99 && v[i][ans+1]) {
                while (v[i][++ans]);
                --ans;
            }
        }
        cout << "#" << test_case << " " << ans << '\n';
    }

    return 0;
}
