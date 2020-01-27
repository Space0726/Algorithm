#include <cstdio>
#include <vector>

using namespace std;

int main() {
    int N, i, j;
    scanf("%d", &N);
    vector<vector<char>> v(2*N - 1, vector<char>(2*N - 1, ' '));
    int cnt = N;
    char ch = 'A';
    while (cnt) {
        for (i = N-cnt, j = N-1; i <= N-1; i++, j--) {
            v[i][j] = ch++;
            if (ch > 'Z')
                ch = 'A';
        }
        --cnt;
        for (i = N, j = N-cnt; i <= N-1+cnt; i++, j++) {
            v[i][j] = ch++;
            if (ch > 'Z')
                ch = 'A';
        }
        for (i = N-2+cnt, j = N; i >= N-1; i--, j++) {
            v[i][j] = ch++;
            if (ch > 'Z')
                ch = 'A';
        }
        --cnt;
        for (i = N-2, j = N-1+cnt; i >= N-cnt-1; i-- ,j--) {
            v[i][j] = ch++;
            if (ch > 'Z')
                ch = 'A';
        }
        ++cnt;
    }
    for (i = 0; i < 2*N - 1; i++) {
        for (j = 0; j < 2*N - 1; j++)
            printf("%c ", v[i][j]);
        putchar('\n');
    }

    return 0;
}
