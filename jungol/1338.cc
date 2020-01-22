#include <cstdio>
#include <vector>

using namespace std;

// Other Answer
void fill() {
    int N, i, j, k;
    char alpha = 'A';
    scanf("%d", &N);
    vector<vector<char>> arr(N, vector<char>(N));
    for (i = 0; i < N; i++) {
        for (j = i, k = N-1; j < N; j++, k--) {
            arr[j][k] = alpha++;
            if (alpha > 'Z')
                alpha = 'A';
        }
    }
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++)
            printf("%c ", arr[i][j] ? arr[i][j] : ' ');
        putchar('\n');
    }
}

int main() {
    int N, i, j, tmp;
    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        tmp = 0;
        for (j = 0; j < N; j++) {
            if (i > N - 1 - j)
                tmp += 2*N - 1 - i - j;
            printf("%c ", N-j <= i+1 ? 'A' + (i+tmp)%26 : 32);
        }
        putchar('\n');
    }

    return 0;
}
