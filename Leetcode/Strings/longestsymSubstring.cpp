//最长对称子串
//manacher

class Solution {
public:
    int manacher(char *str) {
        int p[1000] = 0;
        int id = 0;
        int mx = 0;

        for (int i = 0; i < strlen(str); i++) {
            p[i] = mx > i ? min(p[2*id - i], mx - i) : 1;
            while (s[i + p[i]] == s[i - p[i]]) {
                p[i]++;
            }
            if (i + p[i] > mx) {
                mx = i + p[i];
                id = i;
            }
        }
        return p[i] - 1;
    } 
};