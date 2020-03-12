#include <iostream>

using namespace std;

int max_heap[1 << 18], e, N;

void push(int a) {
    int cur = ++e;
    while (cur > 1 && max_heap[cur >> 1] < a) {
        max_heap[cur] = max_heap[cur >> 1];
        cur >>= 1;
    }
    max_heap[cur] = a;
}

int pop() {
    int cur = 1, child = 2, ret = max_heap[1];
    e--;
    while (child <= e) {
        // If right child is out of bound
        if (child + 1 <= e && max_heap[child] < max_heap[child + 1])
            ++child;
        if (max_heap[child] <= max_heap[e + 1])
            break;
        max_heap[cur] = max_heap[child];
        cur = child;
        child <<= 1;
    }
    max_heap[cur] = max_heap[e + 1];
    return ret;
}

int main() {
    int tmp;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &tmp);
        push(tmp);
    }
    while (e)
        printf("pop: %d\n", pop());
    putchar('\n');
    return 0;
}
