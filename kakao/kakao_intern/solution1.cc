#include <vector>
#include <stack>

using namespace std;

int get_obj(vector<vector<int>>& b, int dir) {
    int target = 0;
    for (int i = 0; i < b.size(); ++i) {
        if (b[i][dir]) {
            target = b[i][dir];
            b[i][dir] = 0;
            break;
        }
    }
    return target;
}

int solution(vector<vector<int>> board, vector<int> moves) {
    int ans = 0;
    stack<int> st;
    for (int i : moves) {
        int target = get_obj(board, i-1);
        if (!target) continue;
        if (!st.empty() && st.top() == target) {
            ++ans;
            while (!st.empty() && st.top() == target) {
                st.pop();
                ++ans;
            }
        } else {
            st.push(target);
        }
    }
    return ans;
}
