#include <cstdio>

using namespace std;

int main() {
    int year;
    scanf("%d", &year);
    if (!(year%4))
        if (year%100)
            puts("1");
        else if (!(year%400))
                puts("1");
        else
            puts("0");
    else 
        puts("0"); 

    return 0;
}
