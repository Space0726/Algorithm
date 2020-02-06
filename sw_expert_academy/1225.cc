#include <cstdio>

using namespace std;

int main(int argc, char** argv) {
    for (int T = 1; T <= 10; ++T) {
        int test_case, i, sub_val = 1, num_ptr = 0;
        int num[8];
        scanf("%d", &test_case);
        for (i = 0; i < 8; ++i)
            scanf(" %d", num + i);

        while (num[num_ptr] - sub_val > 0) {
            num[num_ptr++] -= sub_val++;
            if (sub_val > 5)
                sub_val = 1;
            if (num_ptr > 7)
                num_ptr = 0;
        }
        num[num_ptr] = num[num_ptr] - sub_val < 0 ? 0 : num[num_ptr] - sub_val;

        printf("#%d ", test_case);
        for (i = num_ptr + 1; i < num_ptr + 8; ++i)
            printf("%d ", num[i % 8]);
        puts("0");
    }
    return 0;
}
