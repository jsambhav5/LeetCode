class Solution {
private:
	bool possible(vector<int>& nums, int k, int mid) {
		long long sum = 0;
		int parts = 1;
		for (int i : nums) {
			sum += i;
			if (sum > mid) {
				parts++;
				sum = i;
			}
		}
		return parts <= k;
	}

public:
	int splitArray(vector<int>& nums, int k) {
		int low = *max_element(nums.begin(), nums.end());
		int high = accumulate(nums.begin(), nums.end(), 0);
		int res = -1;

		while (low <= high) {
			int mid = (low + high) / 2;
			if (possible(nums, k, mid)) {
				res = mid;
				high = mid - 1;
			}
			else low = mid + 1;
		}
		return res;
	}
};
