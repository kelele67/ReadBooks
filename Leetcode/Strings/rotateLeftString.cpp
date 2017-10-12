//On, O1
// abcdef -> cdefab//
// string length = n, move m to tail

class Solution {
public:
    void reverseString(char *s, int from, int to) {
        while (from < to) {
            char t = s[from];
            s[from++] = s[to];
            s[to--] = t;
        }
    }

    void rotateString(char *s, int n, int m) {
        m %= n;
        reverseString(s, 0, m - 1);
        reverseString(s, m, n - 1);
        reverseString(s, 0, n - 1);
    }
};