#include <iostream>

using namespace std;

int visited[8] = {0,};
int stack[10], top = -1; // For dfs stack
int G[8][3];    // Not use index 0, 7 nodes and maximum 3 adjacent nodes graph
int q[10], f = -1, r = -1; // For bfs queue

void dfsr(int v) {
    visited[v] = 1;
    cout << v << " ";

    for (int i = 0; i < 3; i++)
        if (G[v][i] && !visited[G[v][i]])
            dfsr(G[v][i]);
}

void dfs(int v) {
    stack[++top] = v;
    while (top != -1) {
        v = stack[top--];
        if (!visited[v]) {
            visited[v] = 1;
            cout << v << " ";

            for (int i = 0; i < 3; i++)
                if (G[v][i] && !visited[G[v][i]])
                    stack[++top] = G[v][i];
        }
    }
}

void bfs(int v) {
    q[++r] = v;
    while (f != r) {
        v = q[++f];
        if (!visited[v]) {
            visited[v] = 1;
            cout << v << " ";
            
            for (int i = 0; i < 3; i++)
                if (G[v][i] && !visited[G[v][i]])
                    q[++r] = G[v][i];
        }
    }
}
