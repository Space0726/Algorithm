#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int n, arr[500000], cnt[8001] = {0,};

int main() {
    int min_ = 4001, max_ = -4001, sum = 0, freq = 0;
    bool is_check = false;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        if (min_ > arr[i]) min_ = arr[i];
        if (max_ < arr[i]) max_ = arr[i];
        sum += arr[i];
        ++cnt[arr[i] + 4000];
    }
    sort(arr, arr + n);
    for (int i = min_ + 4000; i <= max_ + 4000; ++i) {
        if (cnt[i] > cnt[freq]) {
            freq = i;
            is_check = false;
        } else if (cnt[i] == cnt[freq] && !is_check) {
            freq = i;
            is_check = true;
        }
    }

    float avg = round((float) sum / n);
    if (-0.1 < avg && avg < 0.1)
        avg = 0;
    cout << avg << "\n" <<  arr[n/2] << "\n" <<  freq - 4000 << "\n" << max_ - min_;
    return 0;
}
