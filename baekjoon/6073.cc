#include <iostream>
#include <cstring>

using namespace std;

int to_number(char ch) { return ch - '0'; }

struct TrieNode {
    TrieNode* children[2];
    bool terminal;
    int link;
    TrieNode(): terminal(false), link(0) {
        memset(children, 0, sizeof(children));
    }
    ~TrieNode() {
        for (int i = 0; i < 2; +i)
            if (children[i])
                delete children[i];
    }
    void insert(const char* key) {
        if (*key == 0) {
            terminal = true;
        } else {
            int next = to_number(*key);
            if (children[next] == NULL)
                children[next] = new TrieNode();
            children[next]->insert(key + 1);
        }
    }
    int find(const char* key) {
        if (*key == 0) return link;
        int next = to_number(*key);
        if (children[next] == NULL) return 1;
        return children[next]->find(key + 1);
    }
};

int main() {


    return 0;
}
