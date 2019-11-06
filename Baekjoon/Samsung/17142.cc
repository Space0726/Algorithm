#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int N, M;
vector<vector<int> > map;
vector<pair<int, int> > virus;

void print_map() {
    for (const auto &m: map) {
        for (const auto &i: m)
            cout << i << " ";
        cout << endl;
    }
    cout << endl;
}

int main(void) {
    freopen("17142_input.txt", "r", stdin);

    cin >> N >> M;
    map = vector<vector<int> > (N, vector<int> (N, 0));
    virus = vector<pair<int, int> > ();

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
            if (map[i][j] == 2)
                virus.push_back(make_pair(i, j));
        }
    }
    print_map();

    int size = virus_size();
    vector<bool> v(size);
    fill(v.begin(), v.begin() + M, true);
    do {
        for (int i = 0; i < size; i++)
            
    } while (next_permutation(v.begin(), v.end()));

    return 0;
}
