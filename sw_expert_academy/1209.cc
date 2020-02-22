#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    for (int test_case = 1; test_case <= 10; test_case++) {
        int i, j, t_r, t_c, diag_left = 0, diag_right = 0, max_r = 0, max_c = 0;
        cin >> i;
        vector<vector<int>> v(100, vector<int>(100));
        for (i = 0; i < 100; i++)
            for (j = 0; j < 100; j++)
                cin >> v[i][j];
        for (i = 0; i < 100; i++) {
            diag_left += v[i][i];
            diag_right += v[i][99-i];
        }
        for (i = 0; i < 100; i++) {
            t_r = 0;
            t_c = 0;
            for (j = 0; j < 100; j++) {
                t_r += v[i][j];
                t_c += v[j][i];
            }
            if (max_r < t_r)
                max_r = t_r;
            if (max_c < t_c)
                max_c = t_c;
        }
        cout << '#' << test_case << ' ' << max(max(max_r, max_c), max(diag_left, diag_right)) << '\n';
    }

    return 0;
}
