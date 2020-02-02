#include <cstdio>

using namespace std;

int main() {
    for (int t = 1; t <= 10; t++) {
        int test_case, find_num, i, j, k;
        char str[100][100];
        scanf("%d", &test_case);
        for (i = 0; i < 100; i++)
            for (j = 0; j < 100; j++)
                scanf(" %c", &str[i][j]);

        bool r_palin, c_palin;
        for (find_num = 100; find_num > 0; find_num--) {
            for (i = 0; i < 100; i++) {
                for (j = 0; j <= 100 - find_num; j++) {
                    r_palin = true;
                    c_palin = true;
                    for (k = 0; k < find_num/2; k++) {
                        if (r_palin && str[i][j + k] != str[i][j + find_num - 1 - k])
                            r_palin = false;
                        if (c_palin && str[j + k][i] != str[j + find_num - 1 - k][i])
                            c_palin = false;
                        if (!r_palin && !c_palin)
                            break;
                    }
                    if (r_palin || c_palin)
                        goto end;
                }
            }
end:
            if (r_palin || c_palin) {
                printf("#%d %d\n", test_case, find_num);
                break;
            }
        }
        
    }

    return 0;
}
