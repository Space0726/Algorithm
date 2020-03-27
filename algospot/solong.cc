#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int ALPHABETS = 26;

int to_number(char ch) { return ch - 'A'; }
struct TrieNode {
    TrieNode* children[ALPHABETS];
    int terminal;
    int first;
    TrieNode(): terminal(-1), first(-1) {
        memset(children, 0, sizeof(children));
    }
    ~TrieNode() {
        for (int i = 0; i < ALPHABETS; ++i)
            if (children[i])
                delete children[i];
    }
    void insert(const char* key, int id) {
        if (first == -1) first = id;
        if (*key == 0) {
            terminal = id;
        } else {
            int next = to_number(*key);
            if (children[next] == NULL)
                children[next] = new TrieNode();
            children[next]->insert(key + 1, id);
        }
    }
    TrieNode* find(const char* key) {
        if (*key == 0) return this;
        int next = to_number(*key);
        if (children[next] == NULL) return NULL;
        return children[next]->find(key + 1);
    }
    int type(const char* key, int id) {
        if (*key == 0) return 0;
        if (first == id) return 1;
        int next = to_number(*key);
        return 1 + children[next]->type(key + 1, id);
    }
};

int count_keys(TrieNode* trie, const char* word) {
    TrieNode* node = trie->find(word);
    if (node == NULL || node->terminal == -1) return strlen(word);
    return trie->type(word, node->terminal);
}

TrieNode* read_input(int words) {
    vector<pair<int, string>> input;
    for (int i = 0; i < words; ++i) {
        char buf[11];
        int freq;
        cin >> buf >> freq;
        input.push_back(make_pair(-freq, buf));
    }
    sort(input.begin(), input.end());
    TrieNode* trie = new TrieNode();
    for (int i = 0; i < input.size(); ++i)
        trie->insert(input[i].second.c_str(), i);
    trie->first = -1;
    return trie;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, M, C, cnt;
    char buf[11];
    cin >> C;
    for (int test_case = 0; test_case < C; ++test_case) {
        cin >> N >> M;
        cnt = M - 1;
        TrieNode* tn = read_input(N);
        for (int i = 0; i < M; ++i) {
            cin >> buf;
            cnt += count_keys(tn, buf);
        }
        cout << cnt << '\n';
    }
    return 0;
}
