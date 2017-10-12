/*
single element (1)
iterator insert (const_iterator position, const value_type& val);

fill (2)
iterator insert (const_iterator position, size_type n, const value_type& val);

range (3)

template <class InputIterator>
iterator insert (const iterator position, InputIterator first, InputIterator last);

move (4)
iterator insert (const_iterator position, value_type&& val);

initializer list (5)
iterator insert (const_iterator position, initializer_list<value_type> il);

*/

// insert into a vector
#include <iostream>
#include <vector>

int main() {
	std::vector<int> myvector (3, 100);
	std::vector<int>::iterator it;

	it = myvector.begin();
	it = myvector.insert(it, 200);

	myvector.insert(it, 2, 300);

	// "it" no longer valid, get a new one
	it = myvector.begin();

	std::vector<int> anothervector(2, 400);
	myvector.insert(it+2, anothervector.begin(), anothervector.end());

	int myarray[] = {501, 502, 505};
	myvector.insert(myvector.begin(), myarray, myarray+3);

	std::cout << "myvector contains: ";
	for (it = myvector.begin(); it < myvector.end(); it++) {
		std::cout << " " << *it;
	}
	std::cout << "\n";

	return 0;
}

// assign vs insert

// 只有当vector为空的时候，assign和insert是相同的。

// 如果vetor是空的，使用assign更好。