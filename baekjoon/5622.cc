#include <cstdio>
#include <cstring>

using namespace std;

int main() {
    int ans = 0;
    char word[16];
    scanf("%s", word);
    for (int i = 0; i < strlen(word); i++) {
        if (word[i] > 82) {
            if (word[i] > 89)
                word[i] -= 2;
            else
                --word[i];
        }
        ans += (word[i] + 1)/3 - 19;
    }
    printf("%d", ans);

    return 0;
}
