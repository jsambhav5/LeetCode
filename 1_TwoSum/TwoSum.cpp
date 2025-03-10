// LeetCode : 1 - Two Sum (https://leetcode.com/problems/two-sum/description/)
// TUF+ : Two Sum (https://takeuforward.org/plus/dsa/arrays/faqs-medium/two-sum)

/*
Topics and Learnings:

Approach:
Used Hashing to solve this

Complexiy Analysis:
TC: O(N)
SC: O(N)
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
private:

public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> hash;
		vector<int> res;
		int n = nums.size();

		for (int i = 0; i < n; i++) {
			int num = nums[i];

			if (hash.find(target - num) != hash.end()) {
				res.push_back(i);
				res.push_back(hash[target - num]);
			}
			else {
				hash[num] = i;
			}
		}

		sort(res.begin(), res.end());
		return res;
	}
};

int main(int argc, const char** argv) {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		int target;
		cin >> target;

		vector<int> arr;

		for (int i = 0; i < n; i++) {
			int input;
			cin >> input;
			arr.push_back(input);
		}

		Solution sol;

		vector<int> res = sol.twoSum(arr, target);

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

4 9
2 7 11 15

3 6
3 2 4

2 6
3 3

Test Output : 1
0 1
1 2
0 1

*/
