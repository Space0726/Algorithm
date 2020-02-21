
// 부분 집합 생성, 반복, 바이너리 카운팅, 재귀

#include <iostream>
using namespace std;

int a[21];
int N = 3;
int cnt = 1;

void reset()
{
	cout << "----------------------------" << endl;
	cnt = 1;
}

void Print()
{
	printf("[%d] : {", cnt++);
	for (int i = 1; i <= N; i++)
		if (a[i]) printf(" %d ", i);
	printf("}\n");
}

void power_set_i()
{
	for (int x1 = 0; x1 < 2; x1++)
	{
		a[1] = x1;
		for (int x2 = 0; x2 < 2; x2++)
		{
			a[2] = x2;
			for (int x3 = 0; x3 < 2; x3++)
			{
				a[3] = x3;
				Print();
			}
		}
	}
}

void power_set_b()
{
	for (int i = 0; i < (1 << N); i++)
	{
		printf("[%d] : {", cnt++);

		for (int j = 0; j < N; j++)
			if (i&(1 << j))
				printf(" %d ", j + 1);

		printf("}\n");
	}
}

void power_set_r(int k)
{
	if (k == N) Print();
	else
	{
		k++;
		a[k] = 1; power_set_r(k);
		a[k] = 0; power_set_r(k);
	}
}


void main()
{
	printf("부분집합 반복문\n");
	power_set_i();
	reset();
	printf("부분집합 바이너리 카운팅\n");
	power_set_b();
	reset();
	printf("부분집합 재귀문\n");
	power_set_r(0);
}


