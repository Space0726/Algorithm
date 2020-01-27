#include <cstdio>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int N, i;
    scanf("%d", &N);
    set<int> s;
    for (i = 1; i <= (int) sqrt(N); i++) {
        if(!(N%i)) {
            s.insert(i);
            s.insert(N/i);
        }
    }
    for (auto it = s.begin(); it != s.end(); ++it)
        printf("%d ", *it);

    return 0;
}
