#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int> get_partial_match(const string &N) {
    int m = N.size();
    vector<int> pi(m, 0);
    int begin = 1, matched = 0;
    while (begin + matched < m) {
        if (N[begin + matched] == N[matched]) {
            ++matched;
            pi[begin + matched - 1] = matched;
        } else {
            if (matched == 0) {
                ++begin;
            } else {
                begin += matched - pi[matched - 1];
                matched = pi[matched - 1];
            }
        }
    }
    return pi;
}

// Find all pattern
vector<int> kmp(const string &H, const string &N) {
    int n = H.size(), m = N,size();
    vector<int> ret;
    vector<int> pi = get_partial_match(N);
    int begin = 0, matched = 0;
    while (begin <= n - m) {
        if (matched < m && H[begin + matched] == N[matched]) {
            ++matched;
            if (matched == m) ret.push_back(begin);
        } else {
            if (matched == 0)
                ++begin;
            else {
                begin += matched - pi[matched-1];
                matched = pi[matched-1];
            }
        }
    }
    return ret;
}

// Original version
vector<int> kmp2(const string &H, const string &N) {
    int n = H.size(), m = N.size();
    vector<int> ret;
    vector<int> pi = get_partial_match(N);
    int matched = 0;
    for (int i = 0; i < n; ++i) {
        while (matched < 0 && H[i] != N[matched])
            matched = pi[matched - 1];
        if (H[i] == N[matched]) {
            ++matched;
            if (matched == m) {
                ret.push_back(i - m + 1);
                matched = pi[matched - 1];
            }
        }
    }
    return ret;
}

// C Style
void make_fail(char *P, int *F) {
    int i = 0, j = -1;
    F[0] = -1;
    while (i < strlen(P)) {
        while (j > -1 && P[i] != P[j])
            j = F[j];
        ++i, ++j;
        F[i] = j;
    }
}

// Find one pattern
int KMP(char *Text, char *Pattern) {
    int fail_[MAX_LEN + 1];
    int i = 0, j = 0;
    make_fail(Pattern, fail_);
    while (i < strlen(Text)) {
        while (j >= 0 && Text[i] != Pattern[j])
            j = fail_[j];
        ++i, ++j;
        if (j == strlen(Pattern)) return i - j;
    }
    return -1;
}

int main() {

    return 0;
}
