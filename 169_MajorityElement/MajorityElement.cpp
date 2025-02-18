// LeetCode : 169 - Majority Element (https://leetcode.com/problems/majority-element/description/)
// TUF+ : Majority Element-I (https://takeuforward.org/plus/dsa/arrays/faqs-hard/majority-element-i)

/*
Approach:
Used Moore's Voting Algorithm to solve this

TC: O(N)
SC: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

// Moore's Voting Algorithm

class Solution {
public:
	int majorityElement(vector<int>& nums) {
		int count = 0, candidate;
		for (int i : nums) {
			if (count == 0)
				candidate = i;
			if (i == candidate)
				count++;
			else
				count--;
		}
		return candidate;
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

		Solution sol;

		int res = sol.majorityElement(arr);
		cout << res << endl;
	}

	return 0;
}

/*
Test Input :
INPUT

Test Output : 1
OUTPUT

*/
