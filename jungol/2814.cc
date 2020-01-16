#include <cstdio>
#include <cstring>

using namespace std;

int bin2dec(char *bin, const int len, int ans, int digit) {
    if (digit < 0)
        return ans;
    return bin2dec(bin, len, ans + (1<<(len - digit))*(bin[digit]-48), digit - 1);
}

int main() {
    char bin[31];
    scanf("%s", bin);
    int len = strlen(bin) - 1;
    printf("%d", bin2dec(bin, len, 0, len));

    return 0;
}
