#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

void print_vector(vector<int> &v);
void bubble_sort(vector<int> &v);
void selection_sort(vector<int> &v);
void insertion_sort(vector<int> &v);
void quick_sort(vector<int> &v, int left, int right);
void merge_sort(vector<int> &v, int left, int right, vector<int> &t);
void radix_sort(vector<int> &v, int p, int k=10);

int main(void) {
    vector<int> numbers = {4,123,6,97,8,3,53,1,9,10};
    vector<int> tmp(10);
    radix_sort(numbers, 3);
    return 0;
}

void print_vector(vector<int> &v) {
    for (int value: v)
        cout << value << ' ';
    cout << endl;
}

// Best: O(n), Worst: O(n^2), Stable
void bubble_sort(vector<int> &v) {
    int temp;
    print_vector(v);
    cout << endl;

    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v.size() - (i+1); j++) {
            if (v[j] > v[j+1]) {
                temp = v[j];
                v[j] = v[j+1];
                v[j+1] = temp;
            }
            print_vector(v);
        }
        cout << endl;
    }
}

// Best: O(n^2), Worst: O(n^2), Unstable
void selection_sort(vector<int> &v) {
    int temp;
    int min;
    print_vector(v);
    cout << endl;

    for (int i = 0; i < v.size() - 1; i++) {
        min = i;
        for (int j = i + 1; j < v.size(); j++)
            if (v[min] > v[j])
                min = j;
        temp = v[i];
        v[i] = v[min];
        v[min] = temp;
        print_vector(v);
        cout << endl;
    }
}

// Best: O(n), Worst: O(n^2), Stable
void insertion_sort(vector<int> &v) {
    int temp;
    print_vector(v);
    cout << endl;

    for (int i = 1; i < v.size(); i++) {
        for (int j = i; j > 0; j--) {
            if (v[j-1] > v[j]) {
                temp = v[j-1];
                v[j-1] = v[j];
                v[j] = temp;
                print_vector(v);
            } else {
                print_vector(v);
                break;
            }
        }
        cout << endl;
    }
}

void swap(vector<int> &v, int a, int b) {
    int t = v[a];
    v[a] = v[b];
    v[b] = t;
}

// For quick sort partition
int partition(vector<int> &v, int left, int right) {
    swap(v, left, (left + right) / 2);
    int i = left, j = right + 1;

    while (i < j) {
        while (v[left] < v[--j]);
        while (i < j && v[left] >= v[++i]);
        if (i < j) swap(v, i, j);
    }
    swap(v, left, i);
    return i;
}

// Best: O(nlogn), Worst: O(n^2), Unstable
void quick_sort(vector<int> &v, int left, int right) {
    if (left >= right)
        return;

    // swap middle and left, pivot is left.
    swap(v, left, (left + right) / 2);
    int i = left, j = right + 1;

    while (i < j) {
        while (v[left] < v[--j]);
        while (i < j && v[left] >= v[++i]);
        if (i < j) swap(v, i, j);
    }

    swap(v, left, i);
    print_vector(v);
    quick_sort(v, left, i - 1);
    quick_sort(v, i + 1, right);
}

// Best: O(nlogn), Worst: O(nlogn), Stable
void merge_sort(vector<int> &v, int left, int right, vector<int> &t) {
    if (left >= right)
        return;

    int mid = (left + right) / 2;
    merge_sort(v, left, mid, t);
    merge_sort(v, mid + 1, right, t);

    int i = left, j = mid + 1;
    for (int k = left; k <= right; ++k) {
        if (j > right)
            t[k] = v[i++];
        else if (i > mid)
            t[k] = v[j++];
        else if (v[i] <= v[j])  // This = makes sorting stable
            t[k] = v[i++];
        else
            t[k] = v[j++];
    }

    print_vector(v);
    for (i = left; i <= right; ++i)
        v[i] = t[i];
    print_vector(v);
}

// Best: O(d*(n + b)) / O(dn), Stable
// d is maximum digit of numbers, b is k(=10)
// Possible: string, integer, ...
// Impossible: float (No digits)
// But more memory needed
// p is most digit number
void radix_sort(vector<int> &v, int p, int k) {
    int size = v.size();
    vector<int> counts(size), temp(size);
    int index, pval;
    print_vector(v);

    // Do counting sort by digit n
    // Using LSD(Least Significant Digit)
    // If use MSD(Most Significant Digit), then n is start p-1 to 0
    for (int n = 0; n < p; ++n) {
        for (int i = 0; i < k; ++i)
            counts[i] = 0;

        pval = (int)pow((double)k, (double)n);
        for (int j = 0; j < size; ++j) {
            index = (int)(v[j] / pval) % k;
            ++counts[index];
        }

        for (int i = 1; i < k; ++i)
            counts[i] += counts[i-1];

        for (int j = size-1; j >= 0; --j) {
            index = (int)(v[j] / pval) % k;
            temp[counts[index] - 1] = v[j];
            --counts[index];
        }
        v = temp;
        print_vector(v);
    }
}
