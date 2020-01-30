#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    // Permutation
    string s = "bceda";
    sort(s.begin(), s.end());
    do {
        cout << s << '\n';
    } while (next_permutation(s.begin(), s.end()));

    // Combination
    int n = 5, r = 3;
    vector<bool> v(n);
    fill(v.begin(), v.begin() + r, true);
    do {
        for (int i = 0; i < n; i++)
            if (v[i])
                cout << i + 1 << " ";
        cout << endl;
    } while (prev_permutation(v.begin(), v.end()));

    return 0;
}
