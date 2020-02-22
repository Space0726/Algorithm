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
        {
            for (int idx = 0; idx <= i; idx++)
                cout << include[idx] << " ";
            cout << endl;
        }
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

    w = vector<int>(n);
    include = vector<bool>(n);

    int total = 0;
    cout << "Type weights: ";
    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
        total += w[i];
    }

    sum_of_subsets(-1, 0, total);

    return 0;
}
