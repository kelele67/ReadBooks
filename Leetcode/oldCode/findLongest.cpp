//经典的动态规划
// 最长公子串
class LongestSubstring {
public:
    int findLongest(string A, int n, string B, int m) {
        // write code here
        int dp[n + 1][m + 1];
        int max = 0;
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; ++i) {
        	for (int j = 1; j <= m; ++j) {
        		if (A[i - 1] == B[j - 1]) {
        			dp[i][j] = dp[i - 1][j - 1] + 1;
        		} else {
        			dp[i][j] = 0;
        		}
        		if (dp[i][j] > max) {
        			max = dp[i][j];
        		}
        	}
        }
        return max;
    }
};