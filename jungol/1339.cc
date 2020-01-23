#include <cstdio>
#include <vector>

using namespace std;

int main() {
    int N, i, j;
    char ch = 'A';
    scanf("%d", &N);
    if (1 > N || 100 < N || !(N&1))
        printf("INPUT ERROR");
    else {
        vector<vector<char>> arr(N, vector<char>(N, ' '));
        for (i = N/2; i >= 0; i--) {
            for (j = i; j < i + 2*(N/2 - i) + 1; j++) {
                arr[j][i] = ch++;
                if (ch > 'Z')
                    ch = 'A';
            }
        }
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++)
                printf("%c ", arr[i][j]);
            putchar('\n');
        }
    }
    return 0;
}
