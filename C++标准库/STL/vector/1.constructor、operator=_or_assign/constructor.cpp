/* constructor
c++11

default (1)
explicit vector (const allocator_type& alloc = allocator_type());

fill (2)
explicit vector (size_type n);
		 vector (size_type n, const value_type& val,
		 	     const allocator_type& alloc = allocator_type());

range (3)
template <class InputIterator>
vector (InputIterator first, InputIterator last,
	    const allocator_type& alloc = allocator_type());

copy (4)
vector (vector&& x);
vector (vector&& x, const allocator_type& alloc);

move (5)
vector (vector&& x);
vector (vector&& x, const allocator_type& alloc);

initializer list (6)
vector (initializer_list<value_type> il,
	    const allocator_type& alloc = allocator_type());
*/
#include <iostream>
#include <vector>

int main() {
	std::vector<int> first; // default (1)
	std::vector<int> second (4, 100); // fill (2)
	std::vector<int> third(second.begin(), second.end()); // range(3)
	std::vector<int> fourth(third); // a copy of third

	// the iterator constructor can also be used to construct from arrays:
	int myints[] = {16, 2, 77, 29};
	std::vector<int> fifth (myints, myints + sizeof (myints) / sizeof(int));

	std::cout << "The contents of fifth are:";
	for (std::vector<int>::iterator it = fifth.begin(); it != fifth.end(); it++) {
		std::cout << ' ' << *it;
		std::cout << '\n';

	return 0;
	}
}