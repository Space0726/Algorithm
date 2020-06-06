#include <iostream>

using namespace std;

struct Node {
    int val;
    Node* next;

    Node(): val(0), next(NULL) {}
    Node(int v): val(v), next(NULL) {}
    Node(int v, Node* n): val(v), next(n) {}
    ~Node() { printf("Deleted %d!\n", val); }
};

Node *head, *e;

void init() {
    head = NULL;
    e = NULL;
}

void push_front(int v) {
    Node* tmp = head;
    head = new Node(v);
    head->next = tmp;
    if (e == NULL) e = head;
}

void push_back(int v) {
    if (e == NULL) {
        e = new Node(v);
        head = e;
    } else {
        e->next = new Node(v);
        e = e->next;
    }
}

Node* find(int v) {
    Node* t = head;
    while (t->val != v) t = t->next;
    return t;
}

void insert(Node* n, int v) {
    Node* t = find(n->val);
    t->next = new Node(v, t->next);
}

void del(int v) {
    Node* t = head;
    while (t->next->val != v) t = t->next;
    Node* tmp = t->next->next;
    delete t->next;
    t->next = tmp;
}

void print_nodes() {
    Node* t = head;
    while (t != e) {
        printf("%d ", t->val);
        t = t->next;
    }
    printf("%d\n\n", t->val);
}

int main() {
    init();

    push_back(1);
    printf("Push Back 1:\t");
    print_nodes();

    push_front(2);
    printf("Push Front 2:\t");
    print_nodes();

    push_back(3);
    printf("Push Back 3:\t");
    print_nodes();

    insert(find(1), 10);
    printf("Insert 10 to 1:\t");
    print_nodes();

    push_back(5);
    printf("Push Back 5:\t");
    print_nodes();

    del(3);
    printf("Delete 3:\t");
    print_nodes();

    return 0;
}
