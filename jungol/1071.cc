#include <cstdio>
#include <vector>

using namespace std;

int main() {
    int n, m, i, factor = 0, multiple = 0;
    scanf("%d", &n);
    vector<int> v(n);
    for (i = 0; i < n; i++)
        scanf(" %d", &v[i]);
    scanf(" %d", &m);
    for (i = 0; i < n; i++) {
        if (!(m%v[i]))
            factor += v[i];
        if (!(v[i]%m))
            multiple += v[i];
    }
    printf("%d\n%d", factor, multiple);

    return 0;
}
