#include <vector>

typedef std::vector<char *> MYARRAY;

// This does the trick
inline const int iterator_to_index(MYARRAY &a, MYARRAY::iterator it) {
	return it - a.begin();
}

int main() {
	MYARRAY a;
	int index;

	a.push_back("one");
	a.push_back("two");
	a.push_back("three");

	for (MYARRAY::iterator it = a.begin(); it != a.end(); it++) {
		index = iterator_to_index(a, it);
		printf("index=%d\n", index);
	}
}