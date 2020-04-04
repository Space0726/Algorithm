#include <iostream>
#include <queue>

using namespace std;

int N;

int find_min() {
    queue<int> q;
    q.push(N);
    int cnt = 0, size, cur;
    while (1) {
        size = q.size();
        for (int i = 0; i < size; ++i) {
            cur = q.front(); q.pop();
            if (cur == 1) return cnt;
            if (!(cur % 3))
                q.push(cur / 3);
            if (!(cur & 1))
                q.push(cur / 2);
            if (cur - 1 > 0)
                q.push(cur - 1);
        }
        ++cnt;
    }
}

int main() {
    scanf("%d", &N);
    printf("%d", find_min());
    return 0;
}
