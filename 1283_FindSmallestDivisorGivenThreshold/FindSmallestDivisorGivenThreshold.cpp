class Solution {
private:
	bool possible(vector<int>& nums, int threshold, int div) {
		int sum = 0;
		int n = nums.size();

		for (int i = 0; i < n; i++) {
			sum += nums[i] / div;

			if (nums[i] % div != 0) sum++;
		}

		return sum <= threshold;
	}

public:
	int smallestDivisor(vector<int>& nums, int threshold) {
		int low = 1, high = INT_MIN;
		int ans = -1;
		for (int i : nums)
			high = max(high, i);

		while (low <= high) {
			int mid = (low + high) / 2;

			if (possible(nums, threshold, mid)) {
				ans = mid;
				high = mid - 1;
			}
			else low = mid + 1;
		}

		return ans;
	}
};