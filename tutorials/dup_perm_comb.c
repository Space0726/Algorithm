
#include <iostream>
using namespace std;

#define N 3
#define R 2
int t[N];
int a[N] = { 1, 2, 3 };
int cnt_r;

void print_arr()
{
	printf("[%d] : ", cnt_r++);

	for (int i = 0; i < R; i++)
		printf("%d ", t[i]);
	printf("\n");
}

void SWAP(int i, int j)
{
	int t = a[i];  a[i] = a[j]; a[j] = t;
}

void reset()
{
	cout << " ----------------------------" << endl;
	cnt_r = 1;
}



void comb_i() // 반복문 조합
{
	int cnt = 1;
	for (int i = 0; i < N - 1; i++)
		for (int j = i + 1; j < N; j++)
			cout << "[" << cnt++ << "] : " << a[i] << " " << a[j] << endl;
}

void pi_i()  // 반복문 중복 순열
{
	int cnt = 1;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cout << "[" << cnt++ << "] : " << a[i] << " " << a[j] << endl;
}

void H_i()  // 반복문 중복 조합
{
	int cnt = 1;
	for (int i = 0; i < N; i++)
		for (int j = i; j < N; j++)
			cout << "[" << cnt++ << "] : " << a[i] << " " << a[j] << endl;
}




void comb_r_1(int n, int r) //  조합 생성 재귀적 알고리즘1
{
	if (r == 0) print_arr();
	else if (n < r) return;
	else
	{
		t[r - 1] = a[n - 1];
		comb_r_1(n - 1, r - 1);
		comb_r_1(n - 1, r);
	}
}

void comb_r_2(int k, int s) // 깊이, 시작숫자 // 조합 생성 재귀적 알고리즘2
{
	if (k == R) print_arr();
	else
	{
		for (int i = s; i <= N + (k - R); i++)
		{
			t[k] = a[i];
			comb_r_2(k + 1, i + 1);
		}
	}
}


void pi_r_1(int n, int r) // 중복 순열 생성 재귀적 알고리즘1
{
	if (r == 0) print_arr();
	else
	{
		for (int i = n - 1; i >= 0; i--)
		{
			SWAP(i, n - 1);
			t[r - 1] = a[n - 1];
			pi_r_1(n, r - 1);
			SWAP(i, n - 1);
		}
	}
}

void pi_r_2(int k) // 깊이  // 중복 순열 생성 재귀적 알고리즘2
{
	if (k == R) print_arr();
	else
	{
		for (int i = 0; i < N; i++)
		{
			t[k] = a[i];
			pi_r_2(k + 1);
		}
	}
}



void H_r_1(int n, int r) //  중복조합 생성 재귀적 알고리즘1
{
	if (r == 0) print_arr();
	else if (n == 0) return; // 주의!!!
	else
	{
		t[r - 1] = a[n - 1];
		H_r_1(n, r - 1);
		H_r_1(n - 1, r);
	}
}


void H_r_2(int k, int s) // 깊이, 시작숫자 // 중복조합 생성 재귀적 알고리즘2
{
	if (k == R) print_arr();
	else
	{
		for (int i = s; i < N; i++)
		{
			t[k] = a[i];
			H_r_2(k + 1, i);
		}
	}
}




void main()
{
	cout << "조합" << endl;
	comb_i();  // 반복문
	reset();
	comb_r_1(N, R);
	reset();
	comb_r_2(0, 0);


	cout << endl << "중복 순열" << endl;
	pi_i();  // 반복문
	reset();
	pi_r_1(N, R);
	reset();
	pi_r_2(0);


	cout << endl << "중복 조합" << endl;
	H_i();  // 반복문
	reset();
	H_r_1(N, R);
	reset();
	H_r_2(0, 0);

}

