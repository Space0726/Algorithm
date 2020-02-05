#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int n;
vector<vector<int>> mat;

int dfs(int x, int y) {
	mat[x][y] = 0;
	int xx, yy, ret = 0;
	for (int i = 0; i < 4; i++) {
		xx = x + dx[i];
		yy = y + dy[i];
		if (xx < 0 || xx >= n || yy < 0 || yy >= n)
			continue;
		if (mat[xx][yy])
			ret += dfs(xx, yy);
	}
	return ret + 1;
}

int main() {
    char t;
    scanf("%d", &n);
    mat = vector<vector<int>>(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf(" %c", &t);
            mat[i][j] = t - 48;
        }
    }

	vector<int> res;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (mat[i][j])
				res.push_back(dfs(i, j));

    int len = res.size();
    sort(res.begin(), res.end());
    printf("%d\n", len);
    for (int i = 0; i < len; i++)
        printf("%d\n", res[i]);

	return 0;
}
