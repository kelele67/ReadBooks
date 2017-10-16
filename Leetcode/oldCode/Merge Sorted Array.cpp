class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int ia = m - 1, ib = n - 1, icur = m + n - 1;
        while(ia >= 0 && ib >= 0){
        	nums1[icur--] = nums1[ia] >= nums2[ib] ? nums1[ia--] : nums2[ib--];
        	//[1, 3, 5, 6] [2, 4, 5, 6, 7]
        	//3， 4， 8
        	//7 = 3(6)>4(7) -> 3(6)  : 4(7)
        	//6 = 2>3
        }
        while(ib >= 0){
        	nums1[icur--] = nums2[ib--];
        }
    }
};