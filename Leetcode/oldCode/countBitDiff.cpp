//想到用异或操作，因为相同为0 不同为1，只要统计1的个数就知道了
class Solution {
public:
    /**
     * 获得两个整形二进制表达位数不同的数量
     * 
     * @param m 整数m
     * @param n 整数n
     * @return 整型
     */
    int countBitDiff(int m, int n) {
    	int diff = m ^ n;
    	bitset<32> bit(diff);
    	return bit.count();
    }
};