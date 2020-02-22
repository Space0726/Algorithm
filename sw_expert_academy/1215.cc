#include <cstdio>

using namespace std;

int main() {
    for (int t = 1; t <= 10; t++) {
        int find_num, i, j, k, ans = 0;
        char str[8][8];
        scanf("%d", &find_num);
        for (i = 0; i < 8; i++)
            for (j = 0; j < 8; j++)
                scanf(" %c", &str[i][j]);

        bool r_palin, c_palin;
        for (i = 0; i < 8; i++) {
            for (j = 0; j <= 8 - find_num; j++) {
                r_palin = true;
                c_palin = true;
                for (k = 0; k < find_num/2; k++) {
                    if (str[i][j + k] != str[i][j + find_num - 1 - k])
                        r_palin = false;
                    if (str[j + k][i] != str[j + find_num - 1 - k][i])
                        c_palin = false;
                    if (!r_palin && !c_palin)
                        break;
                }
                if (r_palin)
                    ++ans;
                if (c_palin)
                    ++ans;
            }
        }
        
        printf("#%d %d\n", t, ans);
    }

    return 0;
}
