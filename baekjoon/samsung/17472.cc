#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;

struct Edge {
    pair<int, int> lands;
    int weight;
    Edge(pair<int, int> l, int w) {
        this->lands = l;
        this->weight = w;
    }
};

struct Land {
    int num;
    pair<int, int> tl;
    pair<int, int> br;
    Land(int n, pair<int, int> tl_, pair<int, int>br_) {
        this->num = n;
        this->tl = tl_;
        this->br = br_;
    }
};

struct LandSet {
    int num;
    LandSet *parent;
    LandSet(int n, LandSet *p) {
        this->num = n;
        this->parent = p;
    }
    int find_root() {
        if (this->parent == NULL)
            return this->num;
        return parent->find_root();
    }
    int get_depth() {
        if (this->parent == NULL)
            return 1;
        return parent->get_depth() + 1;
    }
};

int n, m, min_len = 1e4;
vector<vector<int>> map;
vector<Land> land_info;
vector<vector<int>> weights;
vector<Edge> edges;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void print_map() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j)
            printf("%d ", map[i][j]);
        putchar('\n');
    }
    putchar('\n');
}

void print_land_info() {
    for (Land &l : land_info) {
        printf("tl: (%d, %d), br: (%d, %d)\n", l.tl.first, l.tl.second, l.br.first, l.br.second);
    }
    putchar('\n');
}

void print_edges() {
    for (Edge &e : edges) {
        printf("from: %d, to: %d, weight: %d\n", e.lands.first, e.lands.second, e.weight);
    }
    putchar('\n');
}

void print_weights() {
    int size = land_info.size();
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j)
            printf("%d ", weights[i][j]);
        putchar('\n');
    }
    putchar('\n');
}

void find_lands() {
    int x, y, xx, yy, cnt = 1;
    vector<vector<bool>> visited(n, vector<bool>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (map[i][j] && !visited[i][j]) {
                int left = m, top = n, right = -1, bottom = -1;
                queue<pair<int, int>> q;
                q.push(make_pair(i, j));
                while (!q.empty()) {
                    x = q.front().first;
                    y = q.front().second;
                    map[x][y] = cnt;
                    if (left > y)
                        left = y;
                    if (top > x)
                        top = x;
                    if (right < y)
                        right = y;
                    if (bottom < x)
                        bottom = x;
                    for (int k = 0; k < 4; ++k) {
                        xx = x + dx[k];
                        yy = y + dy[k];
                        if (xx < 0 || xx >= n || yy < 0 || yy >= m || visited[xx][yy] || !map[xx][yy])
                            continue;
                        visited[xx][yy] = true;
                        q.push(make_pair(xx, yy));
                    }
                    q.pop();
                }
                land_info.push_back(Land(cnt, make_pair(top, left), make_pair(bottom, right)));
                ++cnt;
            }
        }
    }
}

void calc_weights() {
    int size = land_info.size(), cnt;
    weights = vector<vector<int>>(size, vector<int>(size));
    for (int i = 0; i < size; ++i) {
        Land cur = land_info[i];
        int cur_num = cur.num - 1;
        bool is_end;
        for (int k = 0; k < 4; ++k) {
            is_end = false;
            switch (k) {
                case 0:
                    for (int x = cur.br.first + 1; x < n; ++x) {
                        cnt = 0;
                        for (int y = cur.tl.second; y <= cur.br.second; ++y) {
                            if (map[x][y]) {
                                if (!weights[cur_num][map[x][y] - 1]) {
                                    if (x - cur.br.first - 1 >= 2) {
                                        weights[cur_num][map[x][y] - 1] = weights[map[x][y] - 1][cur_num] = x - cur.br.first - 1;
                                        edges.push_back(Edge(make_pair(cur_num, map[x][y] - 1), x - cur.br.first - 1));
                                    }
                                    else {
                                        weights[cur_num][map[x][y] - 1] = weights[map[x][y] - 1][cur_num] = 1;
                                    }
                                }
                                if (++cnt == cur.br.second - cur.tl.second + 1) {
                                    is_end = true;
                                    break;
                                }
                            }
                        }
                        if (is_end)
                            break;
                    }
                    break;
                case 1:
                    for (int x = cur.tl.first - 1; x >= 0; --x) {
                        cnt = 0;
                        for (int y = cur.tl.second; y <= cur.br.second; ++y) {
                            if (map[x][y]) {
                                if (!weights[cur_num][map[x][y] - 1]) {
                                    if (cur.tl.first - x - 1 >= 2) {
                                        weights[cur_num][map[x][y] - 1] = weights[map[x][y] - 1][cur_num] = cur.tl.first - x - 1;
                                        edges.push_back(Edge(make_pair(cur_num, map[x][y] - 1), cur.tl.first - x - 1));
                                    }
                                    else {
                                        weights[cur_num][map[x][y] - 1] = weights[map[x][y] - 1][cur_num] = 1;
                                    }
                                }
                                if (++cnt == cur.br.second - cur.tl.second + 1) {
                                    is_end = true;
                                    break;
                                }
                            }
                        }
                        if (is_end)
                            break;
                    }
                    break;
                case 2:
                    for (int y = cur.br.second + 1; y < m; ++y) {
                        cnt = 0;
                        for (int x = cur.tl.first; x <= cur.br.first; ++x) {
                            if (map[x][y]) {
                                if (!weights[cur_num][map[x][y] - 1]) {
                                    if (y - cur.br.second - 1 >= 2) {
                                        weights[cur_num][map[x][y] - 1] = weights[map[x][y] - 1][cur_num] = y - cur.br.second - 1;
                                        edges.push_back(Edge(make_pair(cur_num, map[x][y] - 1), y - cur.br.second - 1));
                                    }
                                    else {
                                        weights[cur_num][map[x][y] - 1] = weights[map[x][y] - 1][cur_num] = 1;
                                    }
                                }
                                if (++cnt == cur.br.first - cur.tl.first + 1) {
                                    is_end = true;
                                    break;
                                }
                            }
                        }
                        if (is_end)
                            break;
                    }
                    break;
                case 3:
                    for (int y = cur.tl.second - 1; y >= 0; --y) {
                        cnt = 0;
                        for (int x = cur.tl.first; x <= cur.br.first; ++x) {
                            if (map[x][y]) {
                                if (!weights[cur_num][map[x][y] - 1]) {
                                    if (cur.tl.second - x - 1 >= 2) {
                                        weights[cur_num][map[x][y] - 1] = weights[map[x][y] - 1][cur_num] = cur.tl.second - x - 1;
                                        edges.push_back(Edge(make_pair(cur_num, map[x][y] - 1), cur.tl.second - x - 1));
                                    }
                                    else {
                                        weights[cur_num][map[x][y] - 1] = weights[map[x][y] - 1][cur_num] = 1;
                                    }
                                }
                                if (++cnt == cur.br.first - cur.tl.first + 1) {
                                    is_end = true;
                                    break;
                                }
                            }
                        }
                        if (is_end)
                            break;
                    }
                    break;
            }
        }
    }
}

void kruskal() {
    sort(edges.begin(), edges.end(), [](auto &a, auto &b) { return a.weight < b.weight; });
    vector<LandSet> land_set;
    int land_size = land_info.size();
    for (int i = 0; i < land_size; ++i)
        land_set.push_back(LandSet(i, NULL));
    int sum = 0;
    for (int i = 0; i < edges.size(); ++i) {
        int from = land_set[edges[i].lands.first].find_root();
        int to = land_set[edges[i].lands.second].find_root();
        if (from == to)
            continue;
        else {
            sum += edges[i].weight;
            land_set[to].parent = &land_set[from];
        }
        if (land_set[0].get_depth() == land_size)
            break;
    }
    if (min_len > sum)
        min_len = sum;
}

int main() {
    freopen("input.txt", "r", stdin);
    scanf("%d %d", &n, &m);
    map = vector<vector<int>>(n, vector<int>(m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            scanf("%d", &map[i][j]);
    find_lands();
    calc_weights();
    kruskal();
    if (!min_len)
        min_len = -1;
    printf("%d", min_len);
}
