#include <cstdio>
#include <vector>

long long sum(std::vector<int> &a) {
    long long answer = 0;
    for (const auto &e: a)
        answer += e;
    return answer;
}

int main() {
    int n;
    std::scanf("%d", &n);
    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::scanf("%d", &a[i]);
    std::printf("%lld", sum(a));

    return 0;
}
