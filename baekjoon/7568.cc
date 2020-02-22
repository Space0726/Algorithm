#include <cstdio>
#include <vector>

using namespace std;

int main() {
    vector<pair<int, int>> people;
    int n, a, b, rank;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &a, &b);
        people.push_back(make_pair(a, b));
    }

    for (int i = 0; i < n; i++) {
        rank = 1;
        for (int j = 0; j < n; j++) {
            if (i == j)
                continue;
            if (people[i].first < people[j].first && people[i].second < people[j].second)
                ++rank;
        }
        printf("%d ", rank);
    }

    return 0;
}
