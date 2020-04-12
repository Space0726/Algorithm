#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int N;
vector<vector<vector<char>>> cube(6);
unordered_map<char, int> m = {{'U', 0}, {'D', 1}, {'F', 2}, {'B', 3}, {'L', 4}, {'R', 5}};
int dirs[6][4][2] = {
    {{2, 0}, {4, 0}, {3, 0}, {5, 0}},
    {{3, 2}, {4, 2}, {2, 2}, {5, 2}},
    {{1, 0}, {4, 3}, {0, 2}, {5, 1}},
    {{1, 2}, {5, 3}, {0, 0}, {4, 1}},
    {{1, 1}, {3, 3}, {0, 1}, {2, 1}},
    {{1, 3}, {2, 3}, {0, 3}, {3, 1}},
};

void init() {
    cube[0] = {{'w', 'w', 'w'}, {'w', 'w', 'w'}, {'w', 'w', 'w'}};
    cube[1] = {{'y', 'y', 'y'}, {'y', 'y', 'y'}, {'y', 'y', 'y'}};
    cube[2] = {{'r', 'r', 'r'}, {'r', 'r', 'r'}, {'r', 'r', 'r'}};
    cube[3] = {{'o', 'o', 'o'}, {'o', 'o', 'o'}, {'o', 'o', 'o'}};
    cube[4] = {{'g', 'g', 'g'}, {'g', 'g', 'g'}, {'g', 'g', 'g'}};
    cube[5] = {{'b', 'b', 'b'}, {'b', 'b', 'b'}, {'b', 'b', 'b'}};
}

void rot90(vector<vector<char>> &v, char dir) {
    vector<vector<char>> tmp(3, vector<char>(3));
    if (dir == '+')
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                tmp[j][2-i] = v[i][j];
    else
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                tmp[2-j][i] = v[i][j];
    v = tmp;
}

void turn_border(vector<vector<vector<char>>> &v, char dir) {
    vector<char> tmp = v[0][0];
    if (dir == '+') {
        v[0][0] = v[3][0];
        v[3][0] = v[2][0];
        v[2][0] = v[1][0];
        v[1][0] = tmp;
    } else {
        v[0][0] = v[1][0];
        v[1][0] = v[2][0];
        v[2][0] = v[3][0];
        v[3][0] = tmp;
    }
}

void turn(char target, char dir) {
    vector<vector<vector<char>>> v(4);
    for (int i = 0; i < 4; ++i)
        v[i] = cube[dirs[m[target]][i][0]];
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < dirs[m[target]][i][1]; ++j)
            rot90(v[i], '+');
    turn_border(v, dir);
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < dirs[m[target]][i][1]; ++j)
            rot90(v[i], '-');
    for (int i = 0; i < 4; ++i)
        cube[dirs[m[target]][i][0]] = v[i];
}

int main() {
    int T;
    char target, dir;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        init();
        for (int i = 0; i < N; ++i) {
            scanf(" %c%c", &target, &dir);
            rot90(cube[m[target]], dir);
            turn(target, dir);
        }
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j)
                printf("%c", cube[0][i][j]);
            putchar('\n');
        }
    }
    return 0;
}
