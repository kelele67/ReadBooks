#include <iostream>
#include <vector>

int main() {
	std::vector<int> foo(3, 0);
	std::vector<int> bar(5, 0);

	bar = foo;
	foo = std::vector<int>();

	std::cout << "Size of foo: " << int(foo.size()) << std::endl;
	std::cout << "Size of bar: " << int(bar.size()) << std::endl;
	return 0;
}

// Size of foo: 0
// Size of bar: 3