// LeetCode : 1482 - Minimum Number of Days to Make m Bouquets (https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets)
// TUF+ : Minimum days to make M bouquets (https://takeuforward.org/plus/dsa/binary-search/on-answers/minimum-days-to-make-m-bouquets)

/*
Topics and Learnings: Binary Search

Approach:
Instead of checking for every no. of days, we can just check for (min + max) / 2
if it is possible, then ans is in left half else ans is in right half

Complexiy Analysis:
TC: O(log(max-min+1) * N)
SC: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

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
	int roseGarden(vector<int>& bloomDay, int m, int k) {
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

int main(int argc, const char** argv) {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<int> arr;

		for (int i = 0; i < n; i++) {
			int input;
			cin >> input;
			arr.push_back(input);
		}

		int m, k;
		cin >> m >> k;

		Solution sol;
		int ans = sol.roseGarden(arr, m, k);
		cout << ans << endl;
	}

	return 0;
}

/*
Test Input :
3

5
1 10 3 10 2
3 1

5
1 10 3 10 2
3 2

8
7 7 7 7 13 11 12 7
2 3

Test Output : 1
3
-1
12

*/
