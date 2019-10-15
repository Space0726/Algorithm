#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > map;
vector<int> cleaner;
int R, C, T;

void spread() {
    vector<vector<int> > copy_map = map;
    int dust_cnt, dust_add;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            dust_cnt = 0;
            if (map[i][j] > 0) {
                dust_add = copy_map[i][j] / 5;
                if (i + 1 < R && map[i+1][j] >= 0) {
                    map[i+1][j] += dust_add;
                    dust_cnt++;
                }
                if (j + 1 < C) {
                    map[i][j+1] += dust_add;
                    dust_cnt++;
                }
                if (i - 1 >= 0 && map[i-1][j] >= 0) {
                    map[i-1][j] += dust_add;
                    dust_cnt++;
                }
                if (j - 1 >= 0 && map[i][j-1] >= 0) {
                    map[i][j-1] += dust_add;
                    dust_cnt++;
                }
                if (dust_cnt)
                    map[i][j] -= dust_add * dust_cnt;
            }
        }
    }
}

void clean() {
    int i, j;

    for (i = cleaner[0]-2; i >= 0; i--)
        map[i+1][0] = map[i][0];
    for (j = 1; j < C; j++)
        map[0][j-1] = map[0][j];
    for (i = 1; i <= cleaner[0]; i++)
        map[i-1][C-1] = map[i][C-1];
    i--;
    for (j = C-2; j > 0; j--)
        map[i][j+1] = map[i][j];
    map[cleaner[0]][1] = 0;

    for (i = cleaner[1]+2; i < R; i++)
        map[i-1][0] = map[i][0];
    for (j = 1; j < C; j++)
        map[R-1][j-1] = map[R-1][j];
    for (i = R-2; i >= cleaner[1]; i--)
        map[i+1][C-1] = map[i][C-1];
    i++;
    for (j = C-2; j > 0; j--)
        map[i][j+1] = map[i][j];
    map[cleaner[1]][1] = 0;
}

int main() {
    cin >> R >> C >> T;
    map = vector<vector<int> > (R, vector<int> (C, 0));
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> map[i][j];
            if (map[i][j] < 0)
                cleaner.push_back(i);
        }
    }

    for (int i = 0; i < T; i++) {
        spread();
        clean();
    }

    int answer = 0;
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            if (map[i][j] > 0)
                answer += map[i][j];

    cout << answer << endl;
    return 0;
}
