#include <cstdio>

using namespace std;

int main() {
    int n[8];
    bool asc = true;
    bool dec = true;
    scanf("%d", n);
    for (int i = 1; i < 8; i++) {
        scanf("%d", n+i);
        if (n[i-1] > n[i] && asc)
            asc = false;
        else if (n[i-1] < n[i] && dec)
            dec = false;
        if (!asc && !dec)
            break;
    }
    if (asc)
        puts("ascending");
    else if (dec)
        puts("descending");
    else
        puts("mixed");

    return 0;
}
