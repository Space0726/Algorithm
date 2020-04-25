#include <cstdio>

int N, n[11], p[4], M = -987987987, m = 987987987;

void f(int i, int s){

    if (i == N - 1){
        if (s > M) M = s;
        if (s < m) m = s;
        return;
    }
    if (p[0] > 0){
        p[0]--;
        f(i + 1, s + n[i + 1]);
        p[0]++;
    }
    if (p[1] > 0){
        p[1]--;
        f(i + 1, s - n[i + 1]);
        p[1]++;
    }
    if (p[2] > 0){
        p[2]--;
        f(i + 1, s * n[i + 1]);
        p[2]++;
    }
    if (p[3] > 0){
        p[3]--;
        f(i + 1, s / n[i + 1]);
        p[3]++;
    }
}

int main(){
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d", &n[i]);
    for (int i = 0; i < 4; i++) scanf("%d", &p[i]);
    f(0, n[0]);
    printf("%d\n%d\n", M, m);
    return 0;
}
