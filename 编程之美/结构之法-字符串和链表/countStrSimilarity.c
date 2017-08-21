//1. A[2, ...] -> B[1, ...]
//2. A[1, ...] -> B[1, ...]
//3. A[2, ...] -> B[2, ...]

// 1、递归
int CalculateStringDistance(string strA, int pABegin, int pAEnd, string strB, int pBBegin, int pBEnd) {
	if (pABegin > pAEnd) {
		if (pBBegin > pBEnd)
			return 0;
		else
			return pBEnd - pBBegin + 1;
	}
	if (pBBegin > pBEnd) {
		if (pABegin > pAEnd)
			return 0;
		else
			return pAEnd - pABegin + 1;
	}
	if (strA[pABegin] == strB[pBBegin]) {
		return CalculateStringDistance(strA, pABegin+1, pAEnd, strB, pBBegin + 1, pBEnd);
	}
	else {
		int t1 = CalculateStringDistance(strA, pABegin+1, pAEnd, strB, pBBegin+2, pBEnd);
		int t2 = CalculateStringDistance(strA, pABegin+2, pAEnd, strB, pBBegin+1, pBEnd);
		int t3 = CalculateStringDistance(strA, pABegin+2, pAEnd, strB, pBBegin+2, pBEnd);
		return minValue(t1, t2, t3) + 1;
	}
}

// 2、递归中，子问题重复计算了
// 动态规划
public class StringSimilar {
	public int fun(String source, String target) {
		int i, j;
		int [][] d = new int[source.length() + 1][target.length() + 1];
		for (i = 1; i < source.length(); i++) {
			d[i][0] = i;
		}
		for (j = 1; j < target.length() + 1; j++) {
			d[0][j] = j;
		}
		// 动态规划填表
		for (i = 1; i < source.length() + 1; i++) {
			for (j = 1; j < target.length() + 1; j++) {
				if (source.substring(i-1, i).equals(target.substring(j-1, j))) {
					d[i][j] = d[i-1][j-1];// source的第i个和target的第j个相同时
				}
				else {
					d[i][j] = min(d[i][j-1]+1, d[i-1][j]+1, d[i-1][j-1]+1);
				}
			}
		}
		return d[source.length()][target.length()];
	}
	private int min(int i, int j, int k) {
		int min = i < j ? i : j;
		min = min < k ? min : k;
		return min;
	}
	public static void main(String[] args) {
		StringSimilar ss = new StringSimilar();
		System.out.println(ss.fun("SONWY", "SUNNY"));
	}
}