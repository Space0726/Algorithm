#include <iostream>
#include <vector>

using namespace std;

const int INF = 0xFFFFFF;
vector<int> touch;
vector<int> length;

struct edge {
    pair<int, int> vertexes;
    int weight;

    bool operator<(const edge &other) const {
        if (this->weight < other.weight)
            return true;
        else if (this->weight == other.weight)
            if (this->vertexes.first < other.vertexes.first)
                return true;
        return false;
    }
};

void dijkstra(int n, const vector<vector<int>> W, vector<edge> &F) {
    int i, vnear;
    edge e;

    touch[0] = 0;
    length[0] = 0;
    for (i = 1; i < n; i++) {
        touch[i] = 0;
        length[i] = W[0][i];
    }

    for (int j = 0; j < n-1; j++) {
        int min = INF;
        for (i = 1; i < n; i++) {
            if (0 <= length[i] && length[i] <= min) {
                min = length[i];
                vnear = i;
            }
        }

        if (W[vnear][touch[vnear]] != INF) {
            e.vertexes.first = vnear;
            e.vertexes.second = touch[vnear];
            e.weight = W[vnear][touch[vnear]];
        } else {
            e.vertexes.first = touch[vnear];
            e.vertexes.second = vnear;
            e.weight = W[touch[vnear]][vnear];
        }
        F.push_back(e);

        for (i = 1; i < n; i++) {
            if (length[vnear] + W[vnear][i] < length[i]) {
                length[i] = length[vnear] + W[vnear][i];
                touch[i] = vnear;
            }
        }
        length[vnear] = -1;
    }
}

void print_edges(vector<edge> &F) {
    for (const auto &e: F) {
        cout << "vertexes: " << e.vertexes.first+1 << ", " << e.vertexes.second+1 << endl;
        cout << "weight: " << e.weight << endl;
    }
}

void print_touch(vector<int> &v) {
    for (const auto &a: v)
        cout << a+1 << " ";
    cout << endl;
}

int main() {
    int n;
    cout << "Type n: ";
    cin >> n;

    touch = vector<int>(n);
    length = vector<int>(n);
    vector<edge> F;
    vector<vector<int>> W(n, vector<int>(n));

    cout << "Type W:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> W[i][j];
            if (W[i][j] < 0)
                W[i][j] = INF;
        }
    }

    dijkstra(n, W, F);

    cout << endl;
    print_edges(F);

    cout << endl;
    print_touch(touch);
    return 0;
}
