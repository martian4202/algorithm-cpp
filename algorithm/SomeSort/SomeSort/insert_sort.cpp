#include <iostream>
#include <vector>
#include "insertsort.h"


using namespace std;

void insertSort(vector<int> &arr) {
	size_t size = arr.size();
	for (int i = 1; i < size; i++) {
		int key = arr.at(i);
		for (int j = i-1; j > 0; j--) {
			if (arr.at(j) > key) {
				arr[j+1] = arr.at(j);
				arr[j] = key;
			}
		}
	}
}