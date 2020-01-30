#include <cstdio>

using namespace std;

int main() {
    int t, tc, i, j, score, max_s;
    scanf("%d", &t);
    for (i = 0; i < t; i++) {
        int scores[101] = {0,};
        max_s = 100;
        scanf(" %d", &tc);
        for (j = 0; j < 1000; j++) {
            scanf(" %d", &score);
            ++scores[score];
        }
        for (j = 100; j >= 0; j--)
            if (scores[max_s] < scores[j])
                max_s = j;
        printf("#%d %d\n", tc, max_s);
    }

    return 0;
}
