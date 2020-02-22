#include <cstdio>

using namespace std;

int main() {
    int n, i;
    float max_score = -1;
    scanf("%d", &n);
    float scores[n];
    for (i = 0; i < n; i++) {
        scanf("%f", scores+i);
        if (max_score < scores[i])
            max_score = scores[i];
    }
    float sum = 0;
    for (i = 0; i < n; i++) {
        scores[i] = scores[i]/max_score*100;
        sum += scores[i];
    }
    printf("%.3f", sum/n);

    return 0;
}
