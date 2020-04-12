#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int N;
vector<vector<vector<char>>> cube(6);
unordered_map<char, int> m = {'L': 0, 'D': 1, 'F': 2, 'B': 3, 'L': 4, 'R': 5};
int dirs[6][4] = {
    {2, 4, 3, 5},
    {2, 5, 3, 4},
    {0, 5, 1, 4},
    {0, 4, 1, 5},
    {0, 2, 1, 3},
    {0, 3, 1, 2}
};

void init() {
    cube[0] = {{'w', 'w', 'w'}, {'w', 'w', 'w'}, {'w', 'w', 'w'}};
    cube[1] = {{'y', 'y', 'y'}, {'y', 'y', 'y'}, {'y', 'y', 'y'}};
    cube[2] = {{'r', 'r', 'r'}, {'r', 'r', 'r'}, {'r', 'r', 'r'}};
    cube[3] = {{'o', 'o', 'o'}, {'o', 'o', 'o'}, {'o', 'o', 'o'}};
    cube[4] = {{'g', 'g', 'g'}, {'g', 'g', 'g'}, {'g', 'g', 'g'}};
    cube[5] = {{'b', 'b', 'b'}, {'b', 'b', 'b'}, {'b', 'b', 'b'}};
}

void rot90(char target, char dir) {
    vector<vector<char>> tmp(3, vector<char>(3));
    if (dir == '+')
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                tmp[j][2-i] = cube[i][j];
    else
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                tmp[2-j][i] = cube[i][j];
    cube[m[target]] = tmp;
}

void turn(char target, char dir) {
    char tmp[3];
    for (int i = 0; i < 3; ++i)
        tmp[i] = cube[m[target]][dirs[m[target]][0]][i];
    if (dir == '+') {

    } else {

    }
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
            rot90(target, dir);
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
