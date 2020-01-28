#include <cstdio>

using namespace std;

struct node {
    int weight;
    bool branch;
    node *next;
    node *other;
    node(int weight, bool branch, node *next, node *other) {
        this->weight = weight;
        this->branch = branch;
        this->next = next;
        this->other = other;
    }
};

int main() {
    int num[10], i;
    for (i = 0; i < 10; i++) {
        scanf(" %d", num+i);
    }
    node a = node(1, false, NULL, NULL);
    printf("%d %d\n", a.weight, a.branch);

    return 0;
}
