#include <cstdio>
#include <cstring>

using namespace std;

int main() {
    int max_idx = 0;
    bool dup = false;
    int alpha[26] = {0,};
    char ch = getchar();
    while (ch != '\n' && ch != EOF) {
        if (96 < ch && ch < 123)
            ++alpha[ch-97];
        else
            ++alpha[ch-65];
        ch = getchar();
    }
    for (int i = 1; i < 26; i++) {
        if (alpha[max_idx] < alpha[i]) {
            max_idx = i;
            dup = false;
        } else if (alpha[i] && alpha[max_idx] == alpha[i])
            dup = true;
    }
    if (dup)
        putchar('?');
    else
        putchar(max_idx + 65);

    return 0;
}
