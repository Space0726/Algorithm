#include <iostream>

using namespace std;

int n, arr[10001] = {0,};

int main() {
    int t, max_ = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &t);
        ++arr[t];
        if (t > max_)
            max_ = t;
    }
    for (int i = 1; i <= max_; ++i)
        for (int j = 0; j < arr[i]; ++j)
            printf("%d\n", i);
    return 0;
}
