#include "sort.h"
#include <vector>
#include <iostream>

using namespace std;

int main() {
	vector<int> v({ 3, 4, 5,1, 2, 8 });
	v = count_sort(v, 8);
	for (unsigned int i = 0; i < v.size(); i++)
		cout << v.at(i) << " ";

	cout << endl;

	system("Pause");
}