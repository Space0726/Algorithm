#include <iostream>
#include <vector>

using namespace std;
void print_vector(vector<vector<int>> &v) {
    for (const auto &i: v) {
        for (const auto &j: i)
            cout << j << " ";
        cout << endl;
    }
    cout << endl;
}

int main(void) {
	vector<vector<int>> triangle = {
        {7,0,0,0,0},
        {3,8,0,0,0},
        {8,1,0,0,0},
        {2,7,4,4,0},
        {4,5,2,6,5}
    };
    
    print_vector(triangle);
    for (int i = triangle.size() - 1; i > 0; i--)
        for (int j = 0; j < i; j++)
            triangle[i][j] > triangle[i][j+1] ? triangle[i-1][j] += triangle[i][j] : triangle[i-1][j] += triangle[i][j+1];

    print_vector(triangle);
    
    cout << triangle[0][0] << endl;
	return 0;
}
