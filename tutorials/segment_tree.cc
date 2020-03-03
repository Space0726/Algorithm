#include <iostream>
#include <vector>

using namespace std;

vector<int> segment_tree, arr;

int init(vector<int> &a, vector<int> &tree, int node, int start, int end) {
    if (start == end)
        return tree[node] = a[start];
    return tree[node] = init(a, tree, node*2, start, (start + end)/2)
                        + init(a, tree, node*2 + 1, (start + end)/2 + 1, end);
}

int sum(vector<int> &tree, int node, int start, int end, int left, int right) {
    // [left, right]와 [start, end]가 겹치지 않을 때
    if (left > end || right < start)
        return 0;
    // [left, right]가 [start, end]를 완전히 포함할 때
    if (left <= start && end <= right)
        return tree[node];
    // [start, end]가 [left, right]를 완전히 포함할 때
    // [left, right]와 [start, end]가 겹쳐져 있는 경우
    return sum(tree, node*2, start, (start + end)/2, left, right)
           + sum(tree, node*2 + 1, (start + end)/2 + 1, end, left, right);
}

void update(vector<int> &tree, int node, int start, int end, int index, int diff) {
    // diff는 바꾸고자 하는 값과 원래 값의 차이
    if (index < start || index > end) return;
    tree[node] = tree[node] + diff;
    // leaf 노드가 아닐 경우 자식까지 업데이트
    if (start != end) {
        update(tree, node*2, start, (start + end)/2, index, diff);
        update(tree, node*2 + 1, (start + end) / 2 + 1, end, index, diff);
    }
}

void print_segment_tree(int node_num) {
    if (node_num > 31 || node_num < 1)
        return;
    print_segment_tree(node_num*2);
    printf("%d ", segment_tree[node_num]);
    print_segment_tree(node_num*2 + 1);
}

int main() {
    for (int i = 0; i <= 16; ++i)
        arr.push_back(i);
    segment_tree = vector<int>(32);
    init(arr, segment_tree, 1, 1, 16);
    print_segment_tree(1);
    cout << endl;
    printf("%d\n", sum(segment_tree, 1, 1, 16, 3, 7));
    update(segment_tree, 1, 1, 16, 3, 4);
    print_segment_tree(1);
    return 0;
}
