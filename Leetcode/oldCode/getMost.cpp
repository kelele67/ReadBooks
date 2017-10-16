// class Bonus {
// public:
//     int getMost(vector<vector<int> > board) {
//         // write code here
//         int i, j;
//         int Sum = 0;
//         int fi = 0;
//         int size = 6;
//         for (i = 0; i < size; ++i) {
//         	for (j = 0; j < size; j++) {
//         		fi =  max(board[i + 1][j], board[i][j + 1]);
//         	    Sum += fi;
//         	}
//         }
//         return Sum;
//     }
// };

class Bonus {
public:
    int getMost(vector<vector<int> > board) {
        int m = board.size();
        int n = board[0].size();
        int dp[m][n];
        dp[0][0] = board[0][0];
        
        //初始化dp的第一行和第一列
        for (int i = 1; i < n; ++i) dp[0][i] = board [0][i] + dp[0][i-1];
        for (int j = 1; j < m; ++j) dp[j][0] = board [j][0] + dp[j-1][0];
        
        //dp
        for (int i = 1; i < m; ++i)
        {
            for (int j = 1; j < n; ++j)
            {
                dp[i][j]= board[i][j] + max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[m-1][n-1];    
    }
};