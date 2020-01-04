#include <cstdio>
#include <cstring>

using namespace std;

int main() {
    int t, r;
    char s[21];
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        scanf("%d ", &r);
        scanf("%[0-9A-Z\\$%*+-./:]", s);
        for (int j = 0; j < strlen(s); j++)
            for (int k = 0; k < r; k++)
                putchar(s[j]);
        putchar('\n');
    }

    return 0;
}
