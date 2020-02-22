#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main() {
    for (int t = 0; t < 10; t++) {
        int test_case, ans = 0;
        string check, str;
        cin >> test_case >> check >> str;
        for (int i = 0; i < str.length(); i++) {
            if (str[i] == check[0]) {
                bool is_match = true;
                for (int j = 1; j < check.length(); j++) {
                    if (str[i+j] != check[j]) {
                        is_match = false;
                        break;
                    }
                }
                if (is_match)
                    ++ans;
            }
        }
        cout << '#' << test_case << ' ' << ans << '\n';
    }

    return 0;
}
