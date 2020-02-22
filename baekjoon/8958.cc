#include <cstdio>
#include <cstring>

using namespace std;

int main() {
    int t, i, j, answer;
    char ox[81];
    int prev;
    scanf("%d ", &t);
    for (i = 0; i < t; i++) {
        scanf("%s", ox);
        prev = 1;
        answer = 0;
        for (j = 0; j < strlen(ox); j++) {
            if (ox[j] == 'O') {
                answer += prev;
                ++prev;
            } else
                if (prev != 1)
                    prev = 1;
        }
        printf("%d\n", answer);
    }

    return 0;
}
