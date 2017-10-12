class Solution {
public:
    void reverseString(char *s, int from, int to) {
        while(from < to) {
            char temp = s[from];
            s[from++] = s[to];
            s[to--] = temp;
        }
    }

    void rotateRightString(char *s, int n, int m) {
        m %= n;
        reverseString(s, 0, n - m);
        reverseString(s, n - m - 1, n - 1);
        reverseString(s, 0, n - 1);
    }
};