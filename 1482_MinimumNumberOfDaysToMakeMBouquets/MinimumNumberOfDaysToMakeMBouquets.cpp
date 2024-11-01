class Solution {
private:
	bool possible(vector<int>& bloomDay, int m, int k, int days) {
		int n = bloomDay.size();
		int bouquets = 0, count = 0;

		for (int i = 0; i < n; i++) {
			if (bloomDay[i] <= days) {
				count++;
			}
			else {
				bouquets += count / k;
				count = 0;
			}
		}
		bouquets += count / k;
		return bouquets >= m;
	}

public:
	int minDays(vector<int>& bloomDay, int m, int k) {
		int mini = INT_MAX, maxi = INT_MIN;
		int ans = -1;

		for (int i : bloomDay) {
			mini = min(mini, i);
			maxi = max(maxi, i);
		}

		while (mini <= maxi) {
			int mid = (mini + maxi) / 2;

			if (possible(bloomDay, m, k, mid)) {
				ans = mid;
				maxi = mid - 1;
			}

			else mini = mid + 1;
		}

		return ans;
	}
};