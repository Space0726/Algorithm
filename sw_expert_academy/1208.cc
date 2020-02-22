#include <iostream>

using namespace std;

int main() {
    for (int test_case = 1; test_case <= 10; test_case++) {
        int dump, i, j, t, min_, max_, flag;
        int h_num[100] = {0,};
        cin >> dump;
        min_ = 101;
        max_ = 0;
        for (i = 0; i < 100; i++) {
            cin >> t;
            for (j = 0; j < t; j++)
                ++h_num[j];
            if (t > max_)
                max_ = t;
            if (t < min_)
                min_ = t;
        }
        --max_;
        --min_;
        while (dump > 0) {
            flag = h_num[max_] + h_num[min_];
            if (flag > 100) {
                dump -= 100 - h_num[min_];
                h_num[max_] -= 100 - h_num[min_];
                h_num[min_] = 100;
                if (dump < 0)
                    break;
                ++min_;
            } else if (flag < 100) {
                dump -= h_num[max_];
                h_num[min_] += h_num[max_];
                h_num[max_] = 0;
                if (dump < 0)
                    break;
                --max_;
            } else {
                dump -= h_num[max_];
                h_num[min_] = 100;
                h_num[max_] = 0;
                if (dump < 0)
                    break;
                ++min_;
                --max_;
            }
            if (max_ - min_ < 1)
                break;
        }
        cout << "#" << test_case << ' ' << max_ - min_ + 1 << '\n';
    }
    return 0;
}
