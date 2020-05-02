#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

int N, A[50], B[50];

// Rearrangement Inequality
// S = A[0]*B[0] + A[1]*B[1] + ... + A[N-1]*B[N-1]
// Max of S: sort(A, A + N); sort(B, B + N);
// Min of S: sort(A, A + N); sort(B, B + N, greater<int>());
int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i)
        scanf("%d", A + i);
    for (int i = 0; i < N; ++i)
        scanf("%d", B + i);
    sort(A, A + N);
    sort(B, B + N, greater<int>());
    int sum = 0;
    for (int i = 0; i < N; ++i)
        sum += A[i]*B[i];
    printf("%d", sum);
    return 0;
}
