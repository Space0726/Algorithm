#include <cstdio>

using namespace std;

int main() {
    int score;
    scanf("%d", &score);
    switch (score / 10) {
        case 10:
            puts("A");
            break;
        case 9:
            puts("A");
            break;
        case 8:
            puts("B");
            break;
        case 7:
            puts("C");
            break;
        case 6:
            puts("D");
            break;
        default:
            puts("F");
            break;
    }

    return 0;
}
