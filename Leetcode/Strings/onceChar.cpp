#include <iostream>
#include <map>
using namespace std;
class Solution {
public:
	char onceChar(char *str) {
		map<char, int> maps;
		while (*str != '\0'){
			maps[*str] += 1;
			str++;
		}
		for
		return 0;
	}
};

int main() {
	Solution sol;
	char str[] = "ssssskkkjjjl";
	cout << sol.onceChar(str) << endl;
	return 0;
}
