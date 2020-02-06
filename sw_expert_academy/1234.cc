#include <cstdio>
#include <cstdlib>

using namespace std;

int main(int argc, char** argv) {
    for (int test_case = 1; test_case <= 10; ++test_case) {
        int n;
        scanf("%d", &n);
        char *str = (char*)malloc(n + 1);
        scanf(" %s", str);
        bool *check = (bool*)calloc(n, sizeof(bool));;

        int padding = 0, added = 0;
        for (int i = 1; i < n; ++i) {
            if (str[i - 1 - added] == str[i]) {
                do {
                    check[i - 1 - padding - added] = check[i + padding] = true;
                    ++padding;
                    if (i - 1 - padding - added < 0 || i + padding >= n)
                        break;
                    for (int j = i - padding - added - 1; check[j] && j >= 0; --j)
                        ++added;
                } while (str[i - 1 - padding - added] == str[i + padding]);
                i += padding - 1;
                padding = 0;
                added = 0;
                for (int j = i; check[j] && j >= 0; --j)
                    ++added;
            }
            else
                added = 0;
        }

        printf("#%d ", test_case);
        for (int i = 0; i < n; ++i)
            if (!check[i])
                putchar(str[i]);
        putchar('\n');
        free(str);
        free(check);
    }
    return 0;
}
