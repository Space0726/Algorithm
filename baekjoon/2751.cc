#include <iostream>

using namespace std;

int n, arr[1000000];

void swap(int a, int b) {
    int t = arr[a];
    arr[a] = arr[b];
    arr[b] = t;
}

void quick_sort(int left, int right) {
    if (left >= right)
        return;
    swap(left, (left + right) / 2);
    int i = left, j = right + 1;
    while (i < j) {
        while (arr[left] < arr[--j]);
        while (i < j && arr[left] >= arr[++i]);
        if (i < j) swap(i, j);
    }
    swap(left, i);
    quick_sort(left, i - 1);
    quick_sort(i + 1, right);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", arr + i);
    quick_sort(0, n - 1);
    for (int i = 0; i < n; ++i)
        printf("%d\n", arr[i]);
    return 0;
}
