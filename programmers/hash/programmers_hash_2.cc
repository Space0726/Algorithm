#include <string>
#include <vector>
#include <cstring>

using namespace std;

int to_number(char ch) { return ch - '0'; }
struct TrieNode {
    TrieNode* children[10];
    int terminal;
    TrieNode(): terminal(0) {
        memset(children, 0, sizeof(children));
    }
    ~TrieNode() {
        for (int i = 0; i < 10; ++i)
            if (children[i] != NULL)
                delete children[i];
    }
    void insert(const char* key) {
        if (*key == 0) {
            terminal = 1;
        } else {
            int next = to_number(*key);
            if (children[next] == NULL)
                children[next] = new TrieNode();
            children[next]->insert(key + 1);
        }
    }
    int find(const char* key) {
        if (*key == 0) {
            for (int i = 0; i < 10; ++i)
                if (children[i]) return 1;
            return  0;
        }
        int next = to_number(*key);
        if (children[next] == NULL) return terminal;
        return children[next]->find(key + 1);
    }
};

bool solution(vector<string> phone_book) {
    TrieNode head;
    for (string& str: phone_book)
        head.insert(str.c_str());
    for (string& str: phone_book)
        if (head.find(str.c_str())) return false; 
    return true;
}
