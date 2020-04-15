#include <iostream>
#include <cstring>

using namespace std;

const int NUM = 10;

int to_index(char ch) { return ch - '0'; }
struct TrieNode {
    TrieNode* children[NUM];
    bool terminal;
    TrieNode(): terminal(false) {
        memset(children, 0, sizeof(children));
    }
    ~TrieNode() {
        for (int i = 0; i < NUM; ++i)
            if (children[i])
                delete children[i];
    }
    void insert(const char* key) {
        if (*key == 0) {
            terminal = true;
        } else {
            int next = to_index(*key);
            if (children[next] == NULL)
                children[next] = new TrieNode();
            children[next]->insert(key + 1);
        }
    }
    bool find(const char* key) {
        if (*key == 0) return true;
        int next = to_index(*key);
        if (children[next] == NULL) return terminal;
        return children[next]->find(key + 1);
    }
};

int main() {
    int T, n;
    bool ans;
    char tmp[11];
    TrieNode* tn;
    scanf("%d", &T);
    while (T--) {
        tn = new TrieNode();
        ans = true;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%s", tmp);
            if (!ans) continue;
            if (tn->find(tmp)) ans = false;
            else tn->insert(tmp);
        }
        printf("%s\n", ans ? "YES" : "NO");
        delete tn;
    }
    return 0;
}
