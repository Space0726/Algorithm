#include <cstdio>
#include <stack>

using namespace std;

int dfs(char map[16][16], int x, int y, int end_x, int end_y) {
    stack<pair<int, int>> st;
    bool visited[16][16] = { false, };
    int dx[4] = { 1, -1, 0, 0 };
    int dy[4] = { 0, 0, 1, -1 };
    st.push(make_pair(x, y));
    visited[x][y] = true;
    while (!st.empty()) {
        x = st.top().first;
        y = st.top().second;
        st.pop();
        for (int i = 0; i < 4; ++i) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (xx == end_x && yy == end_y)
                return 1;
            if (map[xx][yy] == '1' || visited[xx][yy] || xx < 0 || xx >= 16 || yy < 0 || yy >= 16)
                continue;
            visited[xx][yy] = true;
            st.push(make_pair(xx, yy));
        }
    }
    return 0;
}

int main(int argc, char** argv) {
    for (int T = 1; T <= 10; ++T) {
        int test_case, i, j, x, y, end_x, end_y;
        char miro[16][16];
        scanf("%d", &test_case);
        for (i = 0; i < 16; ++i) {
            for (j = 0; j < 16; ++j) {
                scanf(" %c", &miro[i][j]);
                if (miro[i][j] == '2')
                    x = i; y = j;
                else if (miro[i][j] == '3')
                    end_x = i; end_y = j;
            }
        }
        printf("#%d %d\n", test_case, dfs(miro, x, y, end_x, end_y));
    }
    return 0;
}
