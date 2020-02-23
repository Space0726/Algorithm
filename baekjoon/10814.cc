#include <iostream>

using namespace std;

struct Member {
    int age;
    char name[101];
    Member() {}
};

int n;
Member members[100000], m[100000];

void strcpy(char *from, char *to) {
    for (; *from; ++from)
        *to++ = *from;
}

void merge_sort(int left, int right, Member *m) {
    if (left >= right)
        return;
    int mid = (left + right) / 2;
    merge_sort(left, mid, m);
    merge_sort(mid + 1, right, m);
    int i = left, j = mid + 1;
    for (int k = left; k <= right; ++k) {
        if (i > mid) m[k] = members[j++];
        else if (j > right) m[k] = members[i++];
        else if (members[i].age <= members[j].age) m[k] = members[i++];
        else m[k] = members[j++];
    }
    for (i = left; i <= right; ++i)
        members[i] = m[i];
}

int main() {
    int t;
    char tmp[101];
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d %s", &t, tmp);
        members[i].age = t;
        strcpy(tmp, members[i].name);
    }
    merge_sort(0, n - 1, m);
    for (int i = 0; i < n; ++i)
        printf("%d %s\n", members[i].age, members[i].name);
    return 0;
}
