#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > map;
vector<pair<int, int> > dust;
vector<pair<int, int> > cleaner;

int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};
int R, C, T;

void clean(void) {
    int y, x, new_y, new_x, ty, tx;
    vector<vector<int> > copy_map;
    vector<pair<int, int> > new_dust;
    copy_map = map;

    for (int i = 0; i < 2; i++) {
        y = cleaner[i].first;
        x = cleaner[i].second;
        map[y][x+1] = 0;
        for (int j = 0; j < 4;) {
            new_y = y + dy[j];
            new_x = x + dx[j];
            if (new_y < 0 || new_y >= R || new_x < 0 || new_x >= C) {
                j++;
                continue;
            }
            if (copy_map[new_y][new_x] >= 0) {
                ty = new_y + dy[j];
                tx = new_x + dx[j];
                if (ty < 0 || ty >= R || tx < 0 || tx >= C) {
                    ty = new_y + dy[(j+1) % 4];
                    tx = new_x + dx[(j+1) % 4];
                }
                if (copy_map[ty][tx] == -1) {
                    break;
                }
                map[ty][tx] = copy_map[new_y][new_x];
            }
            if (copy_map[new_y][new_x] == -1)
                break;

            y = new_y;
            x = new_x;
        }
        dy[1] *= -1;
        dy[3] *= -1;
    }
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            if (map[i][j] > 0)
                new_dust.push_back(make_pair(i, j));
    dust = new_dust;
}

int main(void) {
    freopen("17144_input.txt", "r", stdin);
    for(int time = 0; time < 8; time++) {
        cin >> R >> C >> T;
        map = vector<vector<int> > (R, vector<int> (C, 0));
        dust = vector<pair<int, int> >();
        cleaner = vector<pair<int, int> >();
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                cin >> map[i][j];
                if (map[i][j] == -1)
                    cleaner.push_back(make_pair(i, j));
                else if (map[i][j] > 0)
                    dust.push_back(make_pair(i, j));
            }
        }

        int dust_cnt, dust_add, y, x, new_y, new_x;
        for (int i = 0; i < T; i++) {
            vector<vector<int> > copy_map;
            copy_map = map;

            for (int j = 0; j < dust.size(); j++) {
                y = dust[j].first;
                x = dust[j].second;
                dust_cnt = 0;
                dust_add = copy_map[y][x] / 5;
                if (dust_add == 0)
                    continue;
                for (int dir = 0; dir < 4; dir++) {
                    new_y = y + dy[dir];
                    new_x = x + dx[dir];
                    if (new_y < 0 || new_y >= R || new_x < 0 || new_x >= C || copy_map[new_y][new_x] == -1)
                        continue;
                    map[new_y][new_x] += dust_add;
                    dust_cnt += dust_add;
                }
                map[y][x] -= dust_cnt;
            }
            clean();
        }

        int answer = 0;
        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++)
                if (map[i][j] > 0)
                    answer += map[i][j];

        cout << answer << endl;
        if (answer == 0)
            break;
    }

    return 0;
}
