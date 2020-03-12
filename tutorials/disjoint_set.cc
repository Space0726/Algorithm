// Disjoint set: Sets that have not intersection.
// A set represents itself by representative element.
#include <iostream>
#define N 100

using namespace std;

// p array saves indexes' parent => representatives.
// rank array saves set's rank value that make operations faster.
// Not ranked tree is slow because tree can be skewed(linear).
int p[N], rank_arr[N];

void make_set(int x) { p[x] = x; }
void make_set_rank(int x) {
    p[x] = x;
    rank_arr[x] = 0;
}

void init() { for (int i = 0; i < N; ++i) make_set(i); }
void init_rank() { for (int i = 0; i < N; ++i) make_set_rank(i); }

// Path compression: Makes nodes' that found until find_set() parent to root, so tree depth decreased and more faster when do the find_set().
int find_set(int x) {
    if (x == p[x]) return x;
    return find_set(p[x]);
}
int find_set_rank(int x) {
    if (x != p[x]) p[x] = find_set_rank(p[x]);
    return p[x];
}

void link(int x, int y) {
    if (rank_arr[x] > rank_arr[y]) {
        p[y] = x;
    } else {
        p[x] = y;
        if (rank_arr[x] == rank_arr[y])
            ++rank_arr[y];
    }
}

void union_set(int x, int y) { p[find_set(y)] = find_set(x); }
void union_set_rank(int x, int y) {
    link(find_set_rank(x), find_set_rank(y));
}

int main() {
    init_rank();
    for (int i = 0; i < 10; ++i)
        printf("%d ", p[i]);
    putchar('\n');
    union_set_rank(1, 3);
    union_set_rank(2, 3);
    union_set_rank(5, 6);
    union_set_rank(6, 8);
    union_set_rank(1, 5);
    union_set_rank(6, 7);
    for (int i = 0; i < 10; ++i)
        printf("%d ", p[i]);
    putchar('\n');
    for (int i = 0; i < 10; ++i)
        printf("%d ", find_set_rank(i));
    putchar('\n');
    for (int i = 0; i < 10; ++i)
        printf("%d ", rank_arr[i]);
    putchar('\n');
    return 0;
}
