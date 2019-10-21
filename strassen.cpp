#include <iostream>
#include <vector>

using namespace std;
vector<vector<int> > mat_sum(vector<vector<int> > A, vector<vector<int> > B)
{
    int n = A.size();
    vector<vector<int> > R(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            R[i][j] = A[i][j] + B[i][j];
        }
    }

    return R;
}

vector<vector<int> > mat_sub(vector<vector<int> > A, vector<vector<int> > B)
{
    int n = A.size();
    vector<vector<int> > R(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            R[i][j] = A[i][j] - B[i][j];
        }
    }

    return R;
}

void mat_subdiv(
    vector<vector<int> > M,
    vector<vector<int> > &M11,
    vector<vector<int> > &M12,
    vector<vector<int> > &M21,
    vector<vector<int> > &M22)
{
    int size = M.size();
    int half = size / 2;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (i < half && j < half)
                M11[i][j] = M[i][j];
            else if (i < half && j >= half)
                M12[i][j-half] = M[i][j];
            else if (i >= half && j < half)
                M21[i-half][j] = M[i][j];
            else if (i >= half && j >= half)
                M22[i-half][j-half] = M[i][j];
        }
    }
}

void mat_join(
    vector<vector<int> > M11,
    vector<vector<int> > M12,
    vector<vector<int> > M21,
    vector<vector<int> > M22,
    vector<vector<int> > &M)
{
    int size = M.size();
    int half = size / 2;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (i < half && j < half)
                M[i][j] = M11[i][j];
            else if (i < half && j >= half)
                M[i][j] = M12[i][j-half];
            else if (i >= half && j < half)
                M[i][j] = M21[i-half][j];
            else if (i >= half && j >= half)
                M[i][j] = M22[i-half][j-half];
        }
    }
}

void strassen(int n, vector<vector<int> > A, vector<vector<int> > B, vector<vector<int> > &C)
{
    if (n <= 1)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < n; k++)
                {
                    C[i][j] += A[i][k] * B[k][j];
                }
            }
        }
    }
    else
    {
        int half = n / 2;

        vector<vector<int> > A11(half, vector<int>(half, 0));
        vector<vector<int> > A12(half, vector<int>(half, 0));
        vector<vector<int> > A21(half, vector<int>(half, 0));
        vector<vector<int> > A22(half, vector<int>(half, 0));
        vector<vector<int> > B11(half, vector<int>(half, 0));
        vector<vector<int> > B12(half, vector<int>(half, 0));
        vector<vector<int> > B21(half, vector<int>(half, 0));
        vector<vector<int> > B22(half, vector<int>(half, 0));

        vector<vector<int> > M1(half, vector<int>(half, 0));
        vector<vector<int> > M2(half, vector<int>(half, 0));
        vector<vector<int> > M3(half, vector<int>(half, 0));
        vector<vector<int> > M4(half, vector<int>(half, 0));
        vector<vector<int> > M5(half, vector<int>(half, 0));
        vector<vector<int> > M6(half, vector<int>(half, 0));
        vector<vector<int> > M7(half, vector<int>(half, 0));

        mat_subdiv(A, A11, A12, A21, A22);
        mat_subdiv(B, B11, B12, B21, B22);

        strassen(n / 2, mat_sum(A11, A22), mat_sum(B11, B22), M1);
        strassen(n / 2, mat_sum(A21, A22), B11, M2);
        strassen(n / 2, A11, mat_sub(B12, B22), M3);
        strassen(n / 2, A22, mat_sub(B21, B11), M4);
        strassen(n / 2, mat_sum(A11, A12), B22, M5);
        strassen(n / 2, mat_sub(A21, A11), mat_sum(B11, B12), M6);
        strassen(n / 2, mat_sub(A12, A22), mat_sum(B21, B22), M7);

        mat_join(mat_sum(mat_sub(mat_sum(M1, M4), M5), M7), 
                 mat_sum(M3, M5), mat_sum(M2, M4),
                 mat_sum(mat_sub(mat_sum(M1, M3), M2), M6), C);
    }
}

void print_matrix(vector<vector<int> > &M)
{
    for (const auto &i: M)
    {
        for (const auto &j: i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int> > A(n, vector<int>(n, 0));
    vector<vector<int> > B(n, vector<int>(n, 0));
    vector<vector<int> > C(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> A[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> B[i][j];
        }
    }

    strassen(n, A, B, C);
    print_matrix(C);

    return 0;
}
