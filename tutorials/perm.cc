

//순열 생성 재귀적 알고리즘1
#include <iostream>
using namespace std;

int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
int tr[10];
int N = 3, R = 2;
int cnt = 1;

void SWAP(int i, int j)
{
    int t = arr[i];  arr[i] = arr[j]; arr[j] = t;
}

void print_arr()
{
    printf("[%d] : ", cnt++);
    for (int i = 0; i < R; i++)
        cout << tr[i] << " ";
    cout << endl;
}

void perm(int n, int r)
{
    if (r == 0) print_arr();
    else
    {
        for (int i = n - 1; i >= 0; i--)
        {
            SWAP(i, n - 1);
            tr[r - 1] = arr[n - 1];
            perm(n - 1, r - 1);
            SWAP(i, n - 1);
        }
    }
}

void main()
{
    perm(N, R);
}




//순열 생성 재귀적 알고리즘2
#include <iostream>
using namespace std;

int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
int N = 3, R = 2;
int cnt = 1;

void SWAP(int i, int j)
{
    int t = arr[i];  arr[i] = arr[j]; arr[j] = t;
}

void print_arr()
{
    printf("[%d] : ", cnt++);
    for (int i = 0; i < R; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void perm(int k)
{
    if (k == R) print_arr();
    else
    {
        for (int i = k; i < N; i++)
        {
            SWAP(k, i);
            perm(k + 1);
            SWAP(k, i);
        }
    }
}

void main()
{
    perm(0);
}




//순열 생성 재귀적 알고리즘3

#include <iostream>
using namespace std;

int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
int tr[10];
int visited[10];
int cnt = 1;

int N = 3, R = 2;

void print_arr()
{
    printf("[%d] : ", cnt++);
    for (int i = 0; i < R; i++)
        cout << tr[i] << " ";
    cout << endl;
}

void perm(int k)
{
    if (k == R) print_arr();
    else
    {
        for (int i = 0; i < N; i++)
        {
            if (visited[i]) continue;

            tr[k] = arr[i];
            visited[i] = 1;
            perm(k + 1);
            visited[i] = 0;
        }
    }
}

void main()
{
    perm(0);
}


