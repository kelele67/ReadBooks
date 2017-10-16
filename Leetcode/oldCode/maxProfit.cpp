// class Stock {
// public:
//     int maxProfit(vector<int> prices, int n) {
//         // write code here
//         if (n < 2) {
//         	return -1;
//         }
//         int dp[n + 1];
//         memset(dp, 0, sizeof(dp));
//         int max;
//         for (i = 1; i < n; ++i) {
//         	if (prices.[i] - prices[i - 1] > 0) {
//         		dp[i] = dp[i - 1] + prices.[i] - prices[i - 1];
//         	} else {
//         		dp[i] = 0;
//         	}
//         	if (dp[i] > max) {
//         		max = dp[i];
//         	}
//         }
//         return max;
//     }
// };

class Stock {
public:
    int maxProfit(vector<int> prices, int n) {
        // write code here

        vector<int> pre_profit(n, 0);
        vector<int> post_profit(n, 0);

        //第i天之前的最大收益
        int min_buy = prices[0];
        for (int i = 1; i < n; i++) {
        	min_buy = min(prices[i], min_buy);
        	pre_profit[i] = max(pre_profit[i - 1], prices[i] - min_buy);
        }

        //第i天之后的最大收益
        int max_sell = prices[n - 1];
        for (int j = n - 2; j >= 0; j--) {
        	max_sell = max(prices[j], max_sell);
        	post_profit[j] = max(post_profit[j + 1], max_sell - prices[j]);
        }

        //把所有i遍历一遍
        int max_profit = 0;
        for (int i = 0; i < n; i++) {
        	max_profit = max(max_profit, pre_profit[i] + post_profit[i]);
        }
        return max_profit;
    }
};