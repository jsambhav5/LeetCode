// LeetCode : 1283 - Find the Smallest Divisor Given a Threshold (https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/)
// TUF+ : Find the smallest divisor (https://takeuforward.org/plus/dsa/binary-search/on-answers/find-the-smallest-divisorr)

/*
Topics and Learnings: Binary Search

Approach: Binary Search On Answers
Instead of checking for every divisor from 1 to max of array, we can just check for (min + max) / 2
where min starts with 1 and max starts with bananas in biggest pile
if possible solution exists, then ans is in left half else ans is in right half

Complexity Analysis:
Complexity Analysis:
TC: O(log(max)*N)
SC: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
	bool possible(vector<int>& nums, int limit, int div) {
		int sum = 0;
		int n = nums.size();

		for (int i = 0; i < n; i++) {
			sum += nums[i] / div;

			if (nums[i] % div != 0) sum++;
		}

		return sum <= limit;
	}

public:
	int smallestDivisor(vector<int>& nums, int limit) {
		int low = 1, high = INT_MIN;
		int ans = -1;
		for (int i : nums)
			high = max(high, i);

		while (low <= high) {
			int mid = (low + high) / 2;

			if (possible(nums, limit, mid)) {
				ans = mid;
				high = mid - 1;
			}
			else low = mid + 1;
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

		int limit;
		cin >> limit;

		Solution sol;

		int ans = sol.smallestDivisor(arr, limit);

		cout << ans << endl;
	}

	return 0;
}

/*
Test Input :
3

5
1 2 3 4 5
8

4
8 4 2 3
10

4
8 4 2 3
4

Test Output : 1
3
2
8

*/
