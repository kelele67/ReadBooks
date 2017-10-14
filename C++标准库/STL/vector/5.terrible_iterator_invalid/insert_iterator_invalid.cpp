#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> v;
	v.push_back(1);

	vector<int>::iterator iter1 = v.begin();
	v.push_back(1);

	int n = *iter1; // shit
	cout << n << endl;
	return 0;
}

// 当vector内存不够的时候，每次扩容50