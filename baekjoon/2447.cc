#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> s;

void init(int n) {
    string stars(n, '*');
    for (int i = 0; i < n; i++)
        s[i] = stars;
}

void empty(int n, int x, int y) {
    int new_n = n/3;
    string empty_str(new_n, ' ');
    for (int i = y + new_n; i < y + 2*new_n; i++)
        s[i].replace(x + new_n, new_n, empty_str);
    if (n <= 3)
        return;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            empty(new_n, x + i*new_n, y + j*new_n);
}

void draw() {
    for (const auto &a: s)
        cout << a << endl;
}

int main() {
    int n;
    cin >> n;
    s = vector<string>(n);

    init(n);
    empty(n, 0, 0);
    draw();

    return 0;
}
