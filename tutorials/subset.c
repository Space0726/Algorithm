// day2 연습3 : 부분집합 합
#include <iostream>
using namespace std;

void main() 
{
	int arr[10] = {-1, 3, -9, 6, 7, -6, 1, 5, 4, -2};
	int sum;
	int count = 0;

	for(int i = 1;i < (1 << 10);i++) //공집합 제외
	{ 
		sum = 0;
		for(int j = 0;j < 10;j++)  
			if( i&(1<<j) ) sum += arr[j];

		if(sum == 0)
		{
			cout << "[" << ++count << "] ";
			for(int j = 0;j < 10;j++)  
				if(i&(1<<j)) 
				{
					cout << arr[j] << " ";
				}
				cout << endl;
		}
	}
}






#include <iostream>
using namespace std;

int a[11];
int cnt;
int N = 10;
int arr[10] = { -1, 3, -9, 6, 7, -6, 1, 5, 4, -2 };


void process_solution()
{
	static int count_ans = 1;
	int sum = 0, empty = 1;

	for (int i = 0; i < N; i++)
		if (a[i] == 1) {
			sum += arr[i]; empty = 0;
		}

	if (sum == 0 && !empty)
	{
		printf("%d : (", count_ans++);
		for (int i = 0; i < N; i++)
			if (a[i] == 1)
				printf(" %d", arr[i]);
		printf(")\n");
	}
}

void solve(int k)
{
	if (k == N)  process_solution();
	else
	{
		a[k] = 1; solve(k+1);
		a[k] = 0; solve(k+1);
	}
}

int main(void)
{
	solve(0);

	return 0;
}
