// LeetCode : 88 - Merge Sorted Array (https://leetcode.com/problems/merge-sorted-array)

/*
Topics and Learnings: Array

Approach:
Used parallel traversal to solve this

Complexiy Analysis:
TC: O(N+M)
SC: O(N+M)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		vector<int> temp;
		int i = 0, j = 0;

		while (i < m && j < n)
			if (nums1[i] <= nums2[j])
				temp.push_back(nums1[i++]);
			else
				temp.push_back(nums2[j++]);

		while (i < m)
			temp.push_back(nums1[i++]);

		while (j < n)
			temp.push_back(nums2[j++]);

		for (int i = 0; i < n + m; i++)
			nums1[i] = temp[i];
	}
};

int main(int argc, const char** argv) {
	int t;
	cin >> t;

	while (t--) {
		int n1, n2;
		cin >> n1 >> n2;

		vector<int> arr1, arr2;

		for (int i = 0; i < n1; i++) {
			int input;
			cin >> input;
			arr1.push_back(input);
		}

		for (int i = 0; i < n2; i++) {
			int input;
			cin >> input;
			arr2.push_back(input);
			arr1.push_back(0);
		}

		Solution sol;

		sol.merge(arr1, n1, arr2, n2);

		for (auto i : arr1) {
			cout << i << " ";
		}

		cout << endl;
	}

	return 0;
}

/*
Test Input :
3

4 3
-5 -2 4 5
-3 1 8

4 3
0 2 7 8
-7 -3 -1

3 4
1 3 5
2 4 6 7

Test Output : 1
-5 -3 -2 1 4 5 8
-7 -3 -1 0 2 7 8
1 2 3 4 5 6 7

*/
