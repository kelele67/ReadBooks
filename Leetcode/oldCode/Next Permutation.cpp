class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		next_Permutation(nums.begin(), nums.end());
	}

	template<typename BidiIt>
	bool next_Permutation(BidiIt first, BidiIt last) {
		//step1 reverse 
		const auto rfirst = reverse_iterator<BidiIt>(last);
		const auto rlast = reverse_iterator<BidiIt>(first);

		//step2 find the first positive permutation
		auto pivot = next(rfirst);
		while(pivot != rlast && *pivot >= *prev(pivot))
			++pivot;
		if (pivot == rlast) {
			reverse(rfirst, rlast);
			return false;
		}
		auto change = find_if(rfirst, pivot, bind1st(less<int>(), *pivot)); // *pivot < x 
		//step3 swap
		swap(*change, *pivot);
		//step4 reverse
		reverse(rfirst, pivot);
		return true;
	}
};