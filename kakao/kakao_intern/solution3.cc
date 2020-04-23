#include <string>
#include <vector>
#include <iostream>

using namespace std;

int N, M, ans;
vector<int> arr;
vector<string> u, b;

bool is_match(string& target, string& pattern) {
    int size = pattern.size();
    if (size != target.size()) return false;
    for (int i = 0; i < size; ++i) {
        if (pattern[i] == '*') continue;
        if (pattern[i] != target[i]) return false;
    }
    return true;
}

bool test_matched() {
    for (int i = 0; i < M; ++i)
        if (!is_match(u[arr[i]], b[i]))
            return false;
    return true;
}

inline void swap(int i, int j) {
    string t = b[i];
    b[i] = b[j];
    b[j] = t;
}

bool perm(int k) {
    if (k == M) {
        if (test_matched()) { ++ans; return true; }
    } else {
        for (int i = k; i < M; ++i) {
            swap(k, i);
            if (perm(k + 1)) return true;
            swap(k, i);
        }
    }
    return false;
}

void comb(int k, int s) {
    if (k == M) {
        perm(0);
    } else {
        for (int i = s; i <= N + (k - M); ++i) {
            arr[k] = i;
            comb(k + 1, i + 1);
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    N = user_id.size(), M = banned_id.size();
    u = user_id, b = banned_id;
    arr = vector<int>(M);
    comb(0, 0);
    return ans;
}
