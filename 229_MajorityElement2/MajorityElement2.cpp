// LeetCode : 229 - Majority Element II (https://leetcode.com/problems/majority-element-ii/description/)
// TUF+ : Majority Element-II (https://takeuforward.org/plus/dsa/arrays/faqs-hard/majority-element-ii)

/*
Topics and Learnings:

Approach:
Used modified Moore's Voting Algorithm to solve this

Complexiy Analysis:
TC: O(N)
SC: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> majorityElement(vector<int>& nums) {
		int n = nums.size();

		int num1 = INT_MIN;
		int num2 = INT_MIN;

		int count1 = 0;
		int count2 = 0;

		for (int i = 0; i < nums.size(); i++) {
			if (count1 == 0 && nums[i] != num2) {
				count1 = 1;
				num1 = nums[i];
			}

			else if (count2 == 0 && nums[i] != num1) {
				count2 = 1;
				num2 = nums[i];
			}

			else if (nums[i] == num1)
				count1++;

			else if (nums[i] == num2)
				count2++;

			else {
				count1--;
				count2--;
			}
		}

		count1 = 0;
		count2 = 0;

		for (int i = 0; i < n; i++) {
			if (nums[i] == num1) count1++;
			if (nums[i] == num2) count2++;
		}

		int min = (n / 3) + 1;

		vector<int> ans;

		if (count1 >= min) ans.push_back(num1);
		if (count2 >= min) ans.push_back(num2);

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

		Solution sol;

		vector<int> res = sol.majorityElement(arr);

		for (auto i : res) {
			cout << i << " ";
		}

		cout << endl;
	}

	return 0;
}

/*
Test Input :
3

6
1 2 1 1 3 2

7
1 2 1 1 3 2 2

8
1 2 1 1 3 2 2 3

Test Output : 1
1
1 2
1 2

*/
