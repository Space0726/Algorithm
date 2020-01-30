#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    freopen("1215_input.txt", "r", stdin);
    for (int t = 1; t <= 10; t++) {
        int find_num, i, j, ans = 0;
        vector<string> v(8);
        cin >> find_num;
        for (i = 0; i < 8; i++)
            cin >> v[i];
        for (i = 0; i < 8; i++) {
            cout << v[i] << endl;
        }
        
        cout << '#' << t << ' ' << ans << '\n';
    }

    return 0;
}
