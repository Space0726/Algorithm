#include <cstdio>

using namespace std;

int main() {
    int n, c, i, j, sum, cnt;
    float avg;
    int scores[1000];
    scanf("%d", &c);
    for (i = 0; i < c; i++) {
        scanf("%d", &n);
        sum = 0;
        cnt = 0;
        for (j = 0; j < n; j++) {
            scanf("%d", scores+j);
            sum += scores[j];
        }
        avg = sum / (float)n;
        for (j = 0; j < n; j++)
            if (scores[j] > avg)
                ++cnt;
        printf("%.3f%\n", cnt / (float)n * 100);
    }

    return 0;
}
