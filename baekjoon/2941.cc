#include <cstdio>

using namespace std;

int main() {
    int ans = 0;
    char ch = getchar();
    char check[4] = {0,};
    while (ch != '\n' && ch != EOF) {
        switch (prev) {
            case 'c':
                if (c == '=' || c == '-')
                    ++ans;
                break;
            case 'd':
                if (c == 'z'
                break;
            case 'l':
                break;
            case 'n':
                break;
            case 's':
                break;
            case 'z':
                break;
            default:
                ++ans;
        }
        prev = ch;
        ch = getchar();
    }
    printf("%d", ans);

    return 0;
}
