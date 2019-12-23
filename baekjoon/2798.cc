#include <iostream>
#include <vector>

using namespace std;
int main() {
    ios_base::sync_with_stdio(false);

    int n, m, i, j, k, temp;
    int max_num = 0;
    cin >> n >> m;
    vector<int> cards(n);
    for (i = 0; i < n; i++)
        cin >> cards[i];
    for (i = 0; i < n; i++)
        for (j = i+1; j < n; j++)
            for (k = j+1; k < n; k++) {
                temp = cards[i] + cards[j] + cards[k];
                if (max_num < temp && temp <= m)
                    max_num = temp;
            }

    cout << max_num << endl;
    return 0;
}
