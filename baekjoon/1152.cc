#include <cstdio>

using namespace std;

int main() {
    int word_cnt = 0;
    char prev, ch = getchar();
    if (ch == ' ') {
        prev = ch;
        ch = getchar();
    }
    while (ch != '\n' && ch != EOF) {
        if (ch == ' ')
            ++word_cnt;
        prev = ch;
        ch = getchar();
    }
    if (prev == ' ')
        printf("%d", word_cnt);
    else
        printf("%d", word_cnt+1);

    return 0;
}
