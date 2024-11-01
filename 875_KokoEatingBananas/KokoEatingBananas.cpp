class Solution {
private:
	bool possible(vector<int> nums, int h, int k) {
		long sum = 0;
		for (int i = 0; i < nums.size(); i++) {
			sum += nums[i] / k;
			if (nums[i] % k != 0) sum++;
		}

		return sum <= h;
	}

public:
	int minEatingSpeed(vector<int> nums, int h) {
		int low = 1, high = INT_MIN;
		int result = -1;

		for (int i : nums)
			high = max(high, i);

		while (low <= high) {
			int mid = (low + high) / 2;

			if (possible(nums, h, mid)) {
				result = mid;
				high = mid - 1;
			}
			else low = mid + 1;
		}

		return result;
	}
};
