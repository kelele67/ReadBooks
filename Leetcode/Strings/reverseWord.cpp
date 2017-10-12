// I am a student. -> student. a am I
#include <iostream>
using namespace std;
class Solution {
public:
    void reverseString(char *s, int from, int to) {
        while (from < to) {
            char temp = s[from];
            s[from++] = s[to];
            s[to--] = temp;
        }
    }
    char *reverseWord(char *s, int start, int end) {
        reverseString(s, 0, strlen(s) - 1);
        while(s[end] != '\0') {
            if (s[end] == ' ') {
                reverseString(s, start, end - 1);
                start = ++end;
            } else {
                end++;
            }
        }
        return s;
    }
};

int main() {
    char str[] = "I am a student.";
    Solution sol;
    string s = sol.reverseWord(str, 0, 0);
    cout << s << endl;
}