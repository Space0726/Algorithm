#include <cstdio>
#include <cmath>

using namespace std;

bool is_prime(int n) {
    for (int i = 2; i <= (int) sqrt(n); i++)
        if (!(n%i))
            return false;
    return true;
}

int main() {
    int num[5], i;
    for (i = 0; i < 5; i++)
        scanf(" %d", num+i);
    for (i = 0; i < 5; i++) {
        if (num[i] == 1)
            printf("number one\n");
        else if (is_prime(num[i]))
            printf("prime number\n");
        else
            printf("composite number\n");
    }

    return 0;
}
