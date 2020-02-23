#include <iostream>

using namespace std;

int price[4], plan[12], min_cost;

void f(int cost, int month) {
    if (month >= 12) {
        if (min_cost > cost)
            min_cost = cost;
        return;
    }
    if (!plan[month]) {
        f(cost, month + 1);
        return;
    }
    int new_cost = cost + plan[month]*price[0];
    if (min_cost > new_cost)
        f(new_cost, month + 1);
    new_cost = cost + price[1];
    if (min_cost > new_cost)
        f(new_cost, month + 1);
    new_cost = cost + price[2];
    if (min_cost > new_cost)
        f(new_cost, month + 3);
    new_cost = cost + price[3];
    if (min_cost > new_cost)
        f(new_cost, month + 12);
}

int min(int a, int b, int c, int d) {
    int t = a;
    if (t > b) t = b;
    if (t > c) t = c;
    if (t > d) t = d;
    return t;
}

int main() {
    int t, start;
    scanf("%d", &t);
    for (int test_case = 1; test_case <= t; ++test_case) {
        int cnts[2] = {0,};
        start = 0;
        scanf("%d%d%d%d", price, price + 1, price + 2, price + 3);
        for (int i = 0; i < 12; ++i) {
            scanf("%d", plan + i);
            if (plan[i]) {
                if (!start)
                    start = i + 1;
                cnts[0] += plan[i];
                ++cnts[1];
            }
        }
        min_cost = min(cnts[0]*price[0], cnts[1]*price[1], price[2]*4, price[3]);
        f(0, start - 1);
        printf("#%d %d\n", test_case, min_cost);
    }
    return 0;
}
