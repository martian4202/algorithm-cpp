#include "sort.h"
#include <vector>
#include <iostream>

using namespace std;

int main() {
	max_heap<int> mh({ 3,4,2,6,7,9,1 });


	mh.build_heap();

	cout << mh[0];


	system("Pause");
}