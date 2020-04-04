#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int solve(int cony, int brown) {
    int time = 0;
    bool visited[200001][2];
    queue<pair<int, int>> q;
    memset(visited, 0, sizeof(visited));
    q.push(make_pair(brown, 0));

    while (1) {
        cony += time;
        if (cony > 200000)
            return -1;
        if (visited[cony][time % 2])
            return time;
        for (int i = 0, size = q.size(); i < size; ++i) {
            int cur = q.front().first;
            int new_time = (q.front().second + 1) % 2;
            int new_pos;
            q.pop();

            new_pos = cur - 1;
            if (new_pos >= 0 && !visited[new_pos][new_time]) {
                visited[new_pos][new_time] = true;
                q.push(make_pair(new_pos, new_time));
            }

            new_pos = cur + 1;
            if (new_pos < 200001 && !visited[new_pos][new_time]) {
                visited[new_pos][new_time] = true;
                q.push(make_pair(new_pos, new_time));
            }

            new_pos = cur * 2;
            if (new_pos < 200001 && !visited[new_pos][new_time]) {
                visited[new_pos][new_time] = true;
                q.push(make_pair(new_pos, new_time));
            }
        }
        ++time;
    }
}

int main() {
    int cony, brown;
    scanf("%d%d", &cony, &brown);
    printf("%d\n", solve(cony, brown));
    return 0;
}
