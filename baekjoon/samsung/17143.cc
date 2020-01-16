#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct shark {
    int r, c;
    int velo;
    int dir;
    int size;
    
    bool operator==(const shark &other) const {
        if (other.r == this->r && other.c == this->c && other.velo == this->velo && other.dir == this->dir && other.size == this->size)
            return true;
        return false;
    }
};

vector<shark> sharks;
vector<vector<shark*> > sea;
int R, C, M;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, 1, -1};

void print_sea() {
    for (const auto &a: sea) {
        for (const auto &b: a) {
            if (b != nullptr)
                cout << b->size << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
    cout << endl;
}

void print_sharks() {
    for (const auto &shark: sharks)
        cout << shark.size << " ";
    cout << endl << endl;
}

void set_sea() {
    for (auto &s: sea)
        for (auto &t: s)
            t = nullptr;
    for (auto s = sharks.begin(); s != sharks.end(); s++)
        sea[s->r][s->c] = &(*s);
}

int catch_shark(int t) {
    shark *temp;
    for (int i = 0; i < C; i++) {
        temp = sea[i][t];
        if (temp != nullptr) {
            int size = temp->size;
            sharks.erase(remove(sharks.begin(), sharks.end(), *temp));
            return size;
        }
    }
}

void move() {
    for (shark &s: sharks) {
        // TODO: Move sharks
    }
}

int main() {
    freopen("17143_input.txt", "r", stdin);
    cin >> R >> C >> M;
    sea = vector<vector<shark*> > (R, vector<shark*> (C, nullptr));

    for (int i = 0; i < M; i++) {
        shark t;
        cin >> t.r >> t.c >> t.velo >> t.dir >> t.size;
        t.r--;
        t.c--;
        t.dir--;
        sharks.push_back(t);
    }

    int answer = 0;
    for (int t = 0; t < C; t++) {
        set_sea();
        answer += catch_shark(t);
        print_sea();
        print_sharks();
    }

    cout << answer << endl;

    return 0;
}
