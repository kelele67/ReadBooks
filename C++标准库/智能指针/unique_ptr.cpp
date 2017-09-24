#include <memory>
using namespace std;

int main() {
	unique_ptr<int> ptr(new int(0));
	return 0;
}