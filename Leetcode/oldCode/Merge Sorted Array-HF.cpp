//考虑从后往前比较，这样就不会产生需要数据后移的问题了。时间复杂度O(n+m)
class Solution{
public:
	void merge(vector<int>& A, int m, vector<int>& B, int n){
		int icur = m + n - 1, ia = m - 1, ib = n - 1;
		while(ia >= 0 && ib >= 0){
			A[icur--] = A[ia] >= B[ib] ? A[ia--] : B[ib--];
		}
		while(ib >= 0){
			A[icur--] = B[ib --];
		}
	}
};