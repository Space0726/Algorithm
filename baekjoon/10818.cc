#include <cstdio>

using namespace std;

int main() {
    int n, t;
    int min_ = 1000001;
    int max_ = -1000001;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &t);
        if (t < min_)
            min_ = t;
        if (t > max_)
            max_ = t;
    }
    printf("%d %d", min_, max_);

    return 0;
}
