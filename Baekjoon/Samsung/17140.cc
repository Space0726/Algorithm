#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
int r, c, k;
vector<vector<int> > arr;

struct Count {
    int num;
    int cnt;

    bool operator<(Count &count) {
        if (count.cnt < this->cnt)
            return false;
        else if (count.cnt == this->cnt)
            return count.cnt > this->cnt;
        return true;
    }
};

map<int, int> counter(vector<int> v) {
    map<int, int> m;
    int size = v.size();
    for (int i = 0; i < size; i++) {
        if (!v[i])
            continue;
        if (m.find(v[i]) == m.end())
            m[v[i]] = 1;
        else
            m[v[i]]++;
    }
    return m;
}

vector<int> map2vec(map<int, int> m) {
    vector<Count> v;
    for (auto it = m.begin(); it != m.end(); it++) {
        Count c;
        c.num = it->first;
        c.cnt = it->second;
        v.push_back(c);
    }
    sort(v.begin(), v.end());
    vector<int> ret;
    for (auto c: v) {
        ret.push_back(c.num);
        ret.push_back(c.cnt);
    }
    return ret;
}

int r_op(int r_size) {
    vector<vector<int> > new_arr(100, vector<int> (100, 0));
    int max_c = -1;
    int size;
    for (int i = 0; i < r_size; i++) {
        vector<int> tmp = map2vec(counter(arr[i]));
        size = tmp.size();
        for (int j = 0; j < size; j++)
            new_arr[i][j] = tmp[j];
        if (max_c < size)
            max_c = size;
    }
    arr = new_arr;
    return max_c;
}

int c_op(int r_size, int c_size) {
    vector<vector<int> > new_arr(100, vector<int> (100, 0));
    int max_r = -1;
    int size;
    for (int i = 0; i < c_size; i++) {
        vector<int> tmp;
        for (int j = 0; j < r_size; j++)
            tmp.push_back(arr[j][i]);
        tmp = map2vec(counter(tmp));
        size = tmp.size();
        if (max_r < size)
            max_r = size;
        for (int j = 0; j < size; j++)
            new_arr[j][i] = tmp[j];
    }
    arr = new_arr;
    return max_r;
}

void print(int r_size, int c_size) {
    for (int i = 0; i < r_size; i++) {
        for (int j = 0; j < c_size; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    freopen("17140_input.txt", "r", stdin);
    for (int tc = 0; tc < 6; tc++) {
    cin >> r >> c >> k;
    r--;
    c--;
    arr = vector<vector<int> > (100, vector<int> (100, 0));

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cin >> arr[i][j];

    //print(3, 3);
    int t = 0;
    int r_size = 3;
    int c_size = 3;
    while (arr[r][c] != k) {
        //print(r_size, c_size);
        if (r_size >= c_size) {
            c_size = r_op(r_size);
        } else {
            r_size = c_op(r_size, c_size);
        }
        //print(r_size, c_size);

        t++;
        if (t > 100)
            break;
    }

    if (t > 100)
        cout << -1 << endl;
    else
        cout << t << endl;
    }

    return 0;
}
