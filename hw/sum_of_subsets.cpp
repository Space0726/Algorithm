#include <iostream>
#include <vector>

using namespace std;

int n, W;
vector<int> w;
vector<bool> include;

bool promising(int i, int weight, int total)
{
    return (weight+total >= W) && (weight == W || weight+w[i+1] <= W);
}

void sum_of_subsets(int i, int weight, int total)
{
    if (promising(i, weight, total))
    {
        if (weight == W)
            cout << include[1]; // through include[i];
        else
        {
            include[i+1] = true;
            sum_of_subsets(i+1, weight+w[i+1], total-w[i+1]);
            include[i+1] = false;
            sum_of_subsets(i+1, weight, total-w[i+1]);
        }
    }
}

int main()
{
    cout << "Type n, W: ";
    cin >> n >> W;

    w = vector<int> (n);
    include = vector<bool> (n);
    for (int i = 0; i < n; i++)
        cout << include[i];
    cout << "Type weights: ";
    for (int i = 0; i < n; i++)
        cin >> w[i];

    sum_of_subsets(0, 0, 0);

    return 0;
}
