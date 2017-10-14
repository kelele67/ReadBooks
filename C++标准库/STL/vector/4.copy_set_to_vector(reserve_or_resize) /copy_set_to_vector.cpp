#include <iostream>
#include <vector>
#include <set>

// 编译通过，运行的时候出现错误。
/*
int main() {
	std::set <double> input;
	input.insert(5);
	input.insert(6);

	std::vector<double> output;
	std::copy(input.begin(), input.end(), output.begin());
	return 0;
}
*/

// 方案一，在定义output的时候，指定其大小
/*
int main() {
	std::set <double> input;
	input.insert(5);
	input.insert(6);

	std::vector<double> output(2); // 指明大小
	std::copy(input.begin(), input.end(), output.begin());
	return 0;
}
*/

// 方案二，使用back_inserter
#include <iterator>
int main() {
	std::set <double> input;
	input.insert(5);
	input.insert(6);

	std::vector<double> output;
	std::copy(input.begin(), input.end(), std::back_inserter(output));
	return 0;
}
