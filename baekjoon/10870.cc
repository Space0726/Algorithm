#include <iostream>

using namespace std;

int fibonacci(int x) {
    if (x < 1)
        return 0;
    else if (x < 3)
        return 1;
    return fibonacci(x-1) + fibonacci(x-2);
}

int main() {
    int n;
    cin >> n;
    cout << fibonacci(n) << endl;

    return 0;
}
