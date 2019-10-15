#include <iostream>
#include <list>

using namespace std;

struct shark {
    int r, c;
    int velo;
    int dir;
    int size;
};

list<shark> sharks;
int R, C, M;

void print() {
    for (const auto &s: sharks) {
        cout << "r: " << s.r << ", c: " << s.c << ", velo: " << s.velo;
        cout << ", dir: " << s.dir << ", size: " << s.size << endl;
    }
}

int main() {
    freopen("17143_input.txt", "r", stdin);
    cin >> R >> C >> M;
    shark t;

    for (int i = 0; i < M; i++) {
        cin >> t.r >> t.c >> t.velo >> t.dir >> t.size;
        sharks.push_back(t);
    }

    print();
    shark *rm;
    for (shark s: sharks)
        if (s.size == 5)
            rm = &s;
    sharks.remove(rm);
    cout << endl;
    print();

    print();

    return 0;
}
