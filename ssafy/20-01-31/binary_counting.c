#include <stdio.h>

// 부분집합 구하기 같은 문제에서
// 0부터 n까지의 정수를 돌면서
// 이를 2진수로 보고 각 비트에
// 해당되는 숫자를 고르는 방법
// 비트 연산 이용
int main() {
    int n = 5;
    int s[5] = {1, 2, 3, 4, 5};
    // shift 연산으로 부분집합 개수 구하기
    // 공집합을 제외할 때는 1부터 시작
    for (int i = 0; i < (1<<n); i++) {
        // 원소 수만큼 비트 비교
        printf("{ ");
        for (int j = 0; j < n; j++)
            if (i&(1<<j))   // 1을 shift연산 후 마스킹, AND 연산을 통해 해당 값 뽑아내기
                printf("%d ", s[j]);
        printf("}");
        putchar('\n');
    }

    return 0;
}
