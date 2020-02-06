#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

int graph[100][102] = { 0, };

struct Node {
    int num;
    int depth;
    Node() {}
    Node(int num, int depth) {
        this->num = num;
        this->depth = depth;
    }
};

int bfs(int start) {
    int i;
    bool visited[100] = { false, };
    queue<Node> q;
    Node prev(start, 1), n;
    q.push(prev);
    visited[start - 1] = true;
    while (!q.empty()) {
        n = q.front();
        if (prev.depth < n.depth || (prev.depth == n.depth && prev.num < n.num))
            prev = n;
        for (i = 0; i < graph[n.num - 1][1]; ++i) {
            if (visited[graph[n.num - 1][i + 2] - 1])
                continue;
            visited[graph[n.num - 1][i + 2] - 1] = true;
            q.push(Node(graph[n.num - 1][i + 2], n.depth + 1));
        }
        q.pop();
    }
    return prev.num;
}

int main(int argc, char** argv) {
    for (int test_case = 1; test_case <= 10; ++test_case) {
        int i, j, n, start, from, to;
        scanf("%d %d", &n, &start);
        memset(graph, 0, sizeof(graph));
        for (i = 0; i < n / 2; ++i) {
            scanf(" %d %d", &from, &to);
            graph[from - 1][graph[from - 1][1] + 2] = to;
            ++graph[from - 1][1];
            ++graph[to - 1][0];
        }
        printf("#%d %d\n", test_case, bfs(start));
    }
    return 0;
}
