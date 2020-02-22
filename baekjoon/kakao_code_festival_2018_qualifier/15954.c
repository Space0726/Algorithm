#include <stdio.h>
#include <math.h>
int main() {
    int n, k, i, j, l;
    double avg, result, sum, dv;
    double min_dv = -1;

    scanf("%d %d", &n, &k);
    
    int li[n];
    
    for(i = 0; i < n; i++)
        scanf("%d", &li[i]);
    
    for(i = k; i <= n; i++) {
        for(j = 0; j <= n - i; j++) {
            int num[i];
            for(l = 0; l < i; l++)
                num[l] = li[j+l];
            avg = 0;
            for(l = 0; l < i; l++)
                avg += num[l];
            avg = avg / i;
            sum = 0;
            for(l = 0; l < i; l++)
                sum += pow(num[l] - avg, 2);
            dv = sum / i;
            if(dv <= min_dv || min_dv == -1)
                min_dv = dv;
        }
    }
    printf("%lf", sqrt(min_dv));

    return 0;
}
