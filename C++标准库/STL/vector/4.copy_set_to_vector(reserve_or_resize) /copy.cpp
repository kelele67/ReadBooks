#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	double darray[10] = {1.0,1.1,1.2,1.3,1.4,1.5,1.6,1.7,1.8,1.9};
	vector<double> vdouble(10);
	vector<double>::iterator outputIterator = vdouble.begin();

	copy(darray, darray+10, outputIterator);

	while (outputIterator != vdouble.end()) {
		cout << *outputIterator << endl;
		outputIterator++;
	}
	return 0;
}