#include <iostream>

using namespace std;

int max_heap[1 << 18], e, N;

void swap(int a, int b) {
    int t = max_heap[a];
    max_heap[a] = max_heap[b];
    max_heap[b] = t;
}

void push(int a) {
    max_heap[++e] = a;
    int cur = e;
    while (cur > 1) {
        if (max_heap[cur >> 1] < max_heap[cur]) {
            swap(cur >> 1, cur);
            cur >>= 1;
        } else {
            break;
        }
    }
}

int pop() {
    int cur = 1, ret = max_heap[1];
    swap(cur, e--);
    while (cur << 1 <= e) {
        // If right child is out of bound
        if ((cur << 1) + 1 > e) {
            if (max_heap[cur << 1] > max_heap[cur])
                swap(cur, cur << 1);
            break;
        }
        if (max_heap[cur << 1] > max_heap[cur]) {
            if (max_heap[cur << 1] < max_heap[(cur << 1) + 1]) {
                swap(cur, (cur << 1) + 1);
                cur = (cur << 1) + 1;
            } else {
                swap(cur, cur << 1);
                cur <<= 1;
            }
        } else if (max_heap[(cur << 1) + 1] > max_heap[cur]) {
            swap(cur, (cur << 1) + 1);
            cur = (cur << 1) + 1;
        } else {
            break;
        }
    }
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
