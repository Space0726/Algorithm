#include <iostream>
#include <vector>

using namespace std;

void print_vector(vector<int> v);
void bubble_sort(vector<int> *v);
void select_sort(vector<int> *v);
void insert_sort(vector<int> *v);

int main(void) {
	vector<int> numbers = {4,2,6,7,8,3,5,1,9,0};
	
	insert_sort(&numbers);

	return 0;
}

void print_vector(vector<int> v) {
	for (int value: v)
		cout << value << ' ';
	cout << endl;
}

// Best: O(n), Worst: O(n^2)
void bubble_sort(vector<int> *v) {
	int temp;
	print_vector(*v);
	cout << endl;

	for (int i = 0; i < v->size(); i++) {
		for (int j = 0; j < v->size() - (i+1); j++) {
			if (v->at(j) > v->at(j+1)) {
				temp = v->at(j);
				v->at(j) = v->at(j+1);
				v->at(j+1) = temp;
			}
			print_vector(*v);
		}
		cout << endl;
	}
}

// Best: O(n^2), Worst: O(n^2)
void select_sort(vector<int> *v) {
	int temp;
	int min;
	print_vector(*v);
	cout << endl;

	for (int i = 0; i < v->size() - 1; i++) {
		min = i;
		for (int j = i + 1; j < v->size(); j++)
			if (v->at(min) > v->at(j))
				min = j;
		temp = v->at(i);
		v->at(i) = v->at(min);
		v->at(min) = temp;
		print_vector(*v);
		cout << endl;
	}
}

// Best: O(n), Worst: O(n^2)
void insert_sort(vector<int> *v) {
	int temp;
	print_vector(*v);
	cout << endl;

	for (int i = 1; i < v->size(); i++) {
		for (int j = i; j > 0; j--) {
			if (v->at(j-1) > v->at(j)) {
				temp = v->at(j-1);
				v->at(j-1) = v->at(j);
				v->at(j) = temp;
				print_vector(*v);
			}
			else {
				print_vector(*v);
				break;
			}
		}
		cout << endl;
	}
}
