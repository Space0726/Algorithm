#include <iostream>
#include <vector>

using namespace std;

const int INF = 0xFFFFFF;
vector<int> nearest;
vector<int> distance_;

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

void prim(int n, const vector<vector<int>> W, vector<edge> &F) {
    int i, vnear, min;
    edge e;
    
    nearest[0] = 0;
    distance_[0] = 0;
    for (i = 1; i < n; i++) {
        nearest[i] = 0;
        distance_[i] = W[0][i];
    }

    for (int j = 0; j < n-1; j++) {
        min = INF;
        for (i = 1; i < n; i++) {
            if (0 <= distance_[i] && distance_[i] <= min) {
                min = distance_[i];
                vnear = i;
            }
        }

        if (vnear < nearest[vnear]) {
            e.vertexes.first = vnear;
            e.vertexes.second = nearest[vnear];
            e.weight = W[vnear][nearest[vnear]];
        } else {
            e.vertexes.first = nearest[vnear];
            e.vertexes.second = vnear;
            e.weight = W[nearest[vnear]][vnear];
        }
        F.push_back(e);
        distance_[vnear] = -1;
        for (i = 1; i < n; i++) {
            if (W[i][vnear] < distance_[i]) {
                distance_[i] = W[i][vnear];
                nearest[i] = vnear;
            }
        }
    }
}

void print_vector(vector<vector<int>> &v) {
    for (const auto &a: v) {
        for (const auto &b: a)
            cout << b << " ";
        cout << endl;
    }
}

void print_edges(vector<edge> &F) {
    for (const auto &e: F) {
        cout << "vertexes: " << e.vertexes.first+1 << ", " << e.vertexes.second+1 << endl;
        cout << "weight: " << e.weight << endl;
    }
}

int main() {
    int n;
    cout << "Type n: ";
    cin >> n;
    vector<vector<int>> W(n, vector<int>(n));
    nearest = vector<int>(n);
    distance_ = vector<int>(n);

    cout << "Type W:" << endl;
    vector<edge> F;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> W[i][j];
            if (W[i][j] < 0)
                W[i][j] = INF;
        }
    }

    cout << endl;
    print_vector(W);

    prim(n, W, F);

    cout << endl;
    print_edges(F);

    return 0;
}
