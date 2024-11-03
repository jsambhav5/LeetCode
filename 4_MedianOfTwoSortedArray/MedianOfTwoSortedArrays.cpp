// LeetCode : 4 - Median of Two Sorted Arrays (https://leetcode.com/problems/median-of-two-sorted-arrays/)
// TUF+ : Median of 2 sorted arrays (https://takeuforward.org/plus/data-structures-and-algorithm/binary-search/faqs/median-of-2-sorted-arrays)

/*
Approach:
Used Binary Search to solve this

TC: O(log(min(size1, size2)))
SC: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int size1 = nums1.size();
		int size2 = nums2.size();

		if (size1 > size2) return findMedianSortedArrays(nums2, nums1);

		int size = size1 + size2;
		int left = (size + 1) / 2;

		int low = 0, high = size1;

		while (low <= high) {
			int mid1 = (low + high) / 2;
			int mid2 = left - mid1;

			int l1 = (mid1 > 0)     ? nums1[mid1 - 1] : INT_MIN;
			int l2 = (mid2 > 0)     ? nums2[mid2 - 1] : INT_MIN;
			int r1 = (mid1 < size1) ? nums1[mid1] : INT_MAX;
			int r2 = (mid2 < size2) ? nums2[mid2] : INT_MAX;

			if (l1 <= r2 && l2 <= r1) {
				if (size % 2 != 0)
					return max(l1, l2);
				return ((float) max(l1, l2) + min(r1, r2)) / 2;
			}

			if (l1 > r2) high = mid1 - 1;
			else low = mid1 + 1;
		}
		return 0;
	}
};

int main() {
	int t;
	cin >> t;

	while (t--) {
		int size1, size2;
		cin >> size1 >> size2;

		vector<int> arr1, arr2;

		for (int i = 0; i < size1; i++) {
			int input;
			cin >> input;
			arr1.push_back(input);
		}

		for (int i = 0; i < size2; i++) {
			int input;
			cin >> input;
			arr2.push_back(input);
		}

		Solution sol;

		double res = sol.findMedianSortedArrays(arr1, arr2);
		cout << res << endl;
	}

	return 0;
}

/*
Test Input : 
3

3 3
2 4 6
1 3 5

3 2
2 4 6
1 3

3 2
2 4 5
1 6

Test Output : 1
3.5
3
4

*/ 