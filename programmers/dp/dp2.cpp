#include <iostream>

using namespace std;

long long fibo[100] = {0,1};
int main(void) {
    long long answer = 2;
    
    int n;
    cin >> n;
    
    for(int i = 2; i <= n; i++)
        fibo[i] = fibo[i-1] + fibo[i-2];
    
    for(int i = 1; i <= n; i++)
        answer += fibo[i] * 2;

    cout << answer << endl;
    
    return 0;
}
