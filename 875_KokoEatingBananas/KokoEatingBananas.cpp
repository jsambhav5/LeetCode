// LeetCode : 875 - Koko Eating Bananas (https://leetcode.com/problems/koko-eating-bananas)
// TUF+ : Koko eating bananas (https://takeuforward.org/plus/dsa/binary-search/on-answers/koko-eating-bananas)

/*
Topics and Learnings: Binary Search

Approach: Binary Search On Answers
Instead of checking for every no. of banas per hour, we can just check for (min + max) / 2
where min starts with 1 and max starts with bananas in biggest pile
if possible solution exists, then ans is in left half else ans is in right half

Complexity Analysis:
Complexity Analysis:
TC: O(N * log(max))
SC: O(1)
*/

#include <bits/stdc++.h>
using namespace std;
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

		int h;
		cin >> h;

		Solution sol;

		int ans = sol.minEatingSpeed(arr, h);

		cout << ans << endl;
	}

	return 0;
}

/*
Test Input :
3

4
7 15 6 3
8

5
25 12 8 14 19
5

4
3 7 6 11
8

Test Output : 1
8
25
4

*/
