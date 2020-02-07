#include <cstdio>
#include <cstdlib>

using namespace std;

int n;

int operate(int *numbers, int *ops) {
    int result = 0;
    for (int i = 1; i < n; i++) {
        switch (ops[i]) {
        case 0:
            result += numbers[i-1] + numbers[i];
            break;
        case 1:
            result += numbers[i-1] - numbers[i];
            break;
        case 2:
            result += numbers[i-1] * numbers[i];
            break;
        case 3:
            result += numbers[i-1] / numbers[i];
            break;
        }
    }
    return result;
}

int main() {
    freopen("input_14888.txt", "r", stdin);
    int i;
    int op[4] = {0,};
    scanf("%d", &n);
    int *a = (int*) malloc(sizeof(int) * n);
    for (i = 0; i < n; i++)
        scanf(" %d", a + i);
    for (i = 0; i < 4; i++)
        scanf(" %d", op + i);



    // for (i = 0; i < n; i++)
        // printf("%d ", *(a + i));
    // for (i = 0; i < 4; i++)
        // printf("%d ", *(op + i));

    free(a);
    return 0;
}
