#include <iostream>
#include <vector>

using namespace std;

int main() {
    for (int test_case = 1; test_case <= 10; test_case++) {
        int n, i, j, lock = 0;
        cin >> n;
        vector<vector<int>> v(n, vector<int>(n));
        vector<pair<int, int>> red;
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                cin >> v[i][j];
                if (v[i][j] == 1)
                    red.push_back(make_pair(i, j));
            }
        }
        for (i = 0; i < red.size(); i++) {
            while(++red[i].first < n) {
                if (v[red[i].first][red[i].second] == 2) {
                    ++lock;
                    break;
                } else if (v[red[i].first][red[i].second] == 1)
                    break;
            }
        }
        cout << '#' << test_case << ' ' << lock << '\n';
    }

    return 0;
}
