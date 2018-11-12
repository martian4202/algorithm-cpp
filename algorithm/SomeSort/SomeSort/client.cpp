//#include <curl/curl.h>
#include <vector>
#include <iterator>
#include <iostream>
#include "insertsort.h"
#include <string>
#include <map>
#include <algorithm>
#include <unordered_map>


using namespace std;

class Man {
public:
	int a;
	Man() :a(10) {};
	~Man() {};

};

static  map<int, int> m = { { 1,1, },{ 2,2 } };

static unordered_map<char, string> digitMap = {
							{ '2', "abc" },
							{ '3', "def" },
							{ '4', "ghi" },
							{ '5', "jkl" },
							{ '6', "mno" },
							{ '7', "pqrs" },
							{ '8', "tuv" },
							{ '9', "wxyz" },
						};

int main() {

	Man man2;


	cout << man2.a << endl;

	cout << digitMap['2'] << endl;
	system("Pause");
}