#include <iostream>
#include <vector>

int main() {
	std::vector<int> first;
	std::vector<int> second;
	std::vector<int> third;

	first.assign(7, 100);
	std::vector<int>::iterator it;
	it = first.begin() + 1;

	second.assign(it, first.end() - 1); // the 5 central values of first

	int myints[] = {2345, 8, 4};
	third.assign(myints, myints+3);

	std::cout << "Size of first: " << int(first.size()) << std::endl;
	std::cout << "Size of second: " << int(second.size()) << std::endl;
	std::cout << "Size of third: " << int(third.size()) << std::endl;
	return 0;
}

// Size of first: 7
// Size of second: 5
// Size of third: 3

// 他们的共同点是：
// replacing its current contents
// modifying its size accordingly
// 但是assign与=相比，用法更多，用处更广而已。