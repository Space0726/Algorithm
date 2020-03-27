#include <iostream>
#include <cstring>

using namespace std;

// For upper alphabets
const int ALPHABETS = 26;

int to_number(char ch) { return ch - 'A'; }
struct TrieNode {
    TrieNode* children[ALPHABETS];
    bool terminal;    // Indicates this node is end or not
    TrieNode(): terminal(false) {
        memset(children, 0, sizeof(children));
    }
    ~TrieNode() {
        for (int i = 0; i < ALPHABETS; ++i)
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
    // Returns if this node is not a terminal node
    TrieNode* find(const char* key) {
        if (*key == 0) return this;
        int next = to_number(*key);
        if (children[next] == NULL) return NULL;
        return children[next]->find(key + 1);
    }
};

int main() {


    return 0;
}
