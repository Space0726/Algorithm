#include <iostream>
#include <vector>

using namespace std;

int tc, n, m;
bool areFriends[10][10];

int countPairings(bool taken[10]) {
    int firstFree = -1;
    for (int i = 0; i < n; ++i) {
        if(!taken[i]) {
            firstFree = i;
            break;
        }
    }
    if (firstFree == -1) return 1;
    int ret = 0;
    for (int pairWith = firstFree+1; pairWith < n; ++pairWith) {
        if (!taken[pairWith] && areFriends[firstFree][pairWith]) {
            taken[firstFree] = taken[pairWith] = true;
            ret += countPairings(taken);
            taken[firstFree] = taken[pairWith] = false;
        }
    }
    return ret;
}

int main() {
    int t1, t2;
    cin >> tc;
    for (int test_case = 0; test_case < tc; ++test_case) {
        cin >> n >> m;
        bool taken[10];
        for (int a = 0; a < 10; ++a)
            for (int b = 0; b < 10; ++b)
                areFriends[a][b] = false;
        for (int a = 0; a < m; ++a) {
            cin >> t1 >> t2;
            areFriends[t1][t2] = true;
        }
        cout << countPairings(taken) << endl;
    }

    return 0;
}
