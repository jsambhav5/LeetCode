class Solution {
private:
	int lowerBound(vector<int>& nums, int x) {
		int ans = nums.size();
		int low = 0, high = ans - 1;

		while (low <= high) {
			int mid = (low + high) / 2;

			if (nums[mid] >= x) {
				ans = mid;
				high = mid - 1;
			}

			else low = mid + 1;
		}

		return ans;
	}

	int upperBound(vector<int>& nums, int x) {
		int ans = nums.size();
		int low = 0, high = ans - 1;

		while (low <= high) {
			int mid = (low + high) / 2;

			if (nums[mid] > x) {
				ans = mid;
				high = mid - 1;
			}

			else low = mid + 1;
		}

		return ans;
	}

public:
	vector<int> searchRange(vector<int>& nums, int target) {
		int n = nums.size();
		int lb = lowerBound(nums, target);
		if (lb == n || nums[lb] != target) return { -1, -1 };
		int ub = upperBound(nums, target);
		return { lb, ub - 1 };
	}
};
