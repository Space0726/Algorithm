#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M, map[10][10], adj[7][7], land_sum = 1;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

struct Dist {
    int x, y, dir, cnt, land_num;
    Dist() {}
    Dist(int a, int b, int c, int d, int e): x(a), y(b), dir(c), cnt(d), land_num(e) {}
};

struct LandDist {
    int from, to, dist;
    LandDist() {}
    LandDist(int a, int b, int c): from(a), to(b), dist(c) {}
    bool operator<(const LandDist& other) const {
        return dist > other.dist;
    }
};

struct Disjoint {
    int p[7], rank[7];
    Disjoint() {
        for (int i = 0; i < land_sum; ++i) {
            p[i] = i;
            rank[i] = 0;
        }
    }
    int find_set(int x) {
        if (x != p[x]) p[x] = find_set(p[x]);
        return p[x];
    }
    void link(int x, int y) {
        if (rank[x] > rank[y]) {
            p[y] = x;
        } else {
            p[x] = y;
            if (rank[x] == rank[y])
                ++rank[y];
        }
    }
    void union_set(int x, int y) {
        link(find_set(x), find_set(y));
    }
};

int kruskal() {
    Disjoint disjnt;
    priority_queue<LandDist> pq;
    int ans = 0;
    for (int i = 1; i <= land_sum; ++i)
        for (int j = i + 1; j <= land_sum; ++j)
            if (adj[i][j] != 2e9) pq.push({i-1, j-1, adj[i][j]});
    if (pq.empty()) return -1;
    while (!pq.empty()) {
        LandDist tmp = pq.top(); pq.pop();
        int p_from = disjnt.find_set(tmp.from);
        int p_to = disjnt.find_set(tmp.to);
        if (p_from != p_to) {
            disjnt.union_set(tmp.from, tmp.to);
            ans += tmp.dist;
        }
    }
    int super_p = disjnt.find_set(0);
    for (int i = 1; i < land_sum; ++i)
        if (super_p != disjnt.find_set(i-1)) return -1;
    return ans;
}

void calc_dist(queue<Dist>& q) {
    int x, y;
    while (!q.empty()) {
        Dist tmp = q.front(); q.pop();
        while (1) {
            tmp.x += dx[tmp.dir], tmp.y += dy[tmp.dir];
            if (tmp.x == -1 || tmp.x == N || tmp.y == -1 || tmp.y == M) break;
            if (map[tmp.x][tmp.y] == tmp.land_num) {
                break;
            } else if (map[tmp.x][tmp.y] == 0) { 
                ++tmp.cnt; continue;
            } else {
                if (tmp.cnt != 1 && adj[tmp.land_num][map[tmp.x][tmp.y]] > tmp.cnt)
                    adj[tmp.land_num][map[tmp.x][tmp.y]] = adj[map[tmp.x][tmp.y]][tmp.land_num] = tmp.cnt;
                break;
            }
        }
    }
}

void find_adj() {
    vector<vector<bool>> visited(N, vector<bool>(M));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            if (map[i][j] && !visited[i][j]) {
                int x, y, xx, yy;
                queue<pair<int, int>> q;
                queue<Dist> q_dist;
                q.push({i, j});
                visited[i][j] = true;
                while (!q.empty()) {
                    x = q.front().first, y = q.front().second; q.pop();
                    for (int k = 0; k < 4; ++k) {
                        xx = x + dx[k], yy = y + dy[k];
                        if (xx == -1 || xx == N || yy == -1 || yy == M)
                            continue;
                        if (visited[xx][yy]) {
                            if (map[xx][yy] == 0)
                                q_dist.push({xx, yy, k, 1, map[i][j]});
                            continue;
                        }
                        if (map[xx][yy] == 0)
                            q_dist.push({xx, yy, k, 1, map[i][j]});
                        else
                            q.push({xx, yy});
                        visited[xx][yy] = true;
                    }
                }
                if (!q_dist.empty()) calc_dist(q_dist);
            }
}

void add_land_num() {
    vector<vector<bool>> visited(N, vector<bool>(M));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            if (map[i][j] && !visited[i][j]) {
                int x, y, xx, yy;
                queue<pair<int, int>> q;
                q.push({i, j});
                visited[i][j] = true;
                map[i][j] = land_sum;
                while (!q.empty()) {
                    x = q.front().first, y = q.front().second; q.pop();
                    for (int k = 0; k < 4; ++k) {
                        xx = x + dx[k], yy = y + dy[k];
                        if (xx == -1 || xx == N || yy == -1 || yy == M || visited[xx][yy] || !map[xx][yy])
                            continue;
                        q.push({xx, yy});
                        map[xx][yy] = land_sum;
                        visited[xx][yy] = true;
                    }
                }
                ++land_sum;
            }
    --land_sum;
}

int main() {
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            scanf("%d", &map[i][j]);
    for (int i = 1; i < 7; ++i)
        for (int j = 1; j < 7; ++j)
            adj[i][j] = 2e9;
    add_land_num();
    find_adj();
    printf("%d", kruskal());
    return 0;
}
