#include <iostream>

using namespace std;

int idt[1 << 18], n, base;

// Update value of idt[a] to b
void update(int a, int b) {
    idt[a] = b;
    a >>= 1;
    // Update parents
    while (a) {
        idt[a] = idt[2*a] + idt[2*a + 1];
        a >>= 1;
    }
}

int range_sum(int a, int b) {
    int sum = 0;
    while (a < b) {
        if (a & 1) sum += idt[a++];
        if (!(b & 1)) sum += idt[b--];
        a >>= 1, b >>= 1;
    }
    if (a == b) sum += idt[a];
    return sum;
}

int main() {
    scanf("%d", &n);
    // Make index tree
    for (base = 1; base < n; base *= 2);
    for (int i = base; i < n + base; ++i)
        scanf("%d", &idt[i]);
    for (int i = base - 1; i > 0; --i)
        idt[i] = idt[2*i] + idt[2*i + 1];
    return 0;
}
