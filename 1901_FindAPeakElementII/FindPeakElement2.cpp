// LeetCode : 1901 - Find a Peak Element II (https://leetcode.com/problems/find-a-peak-element-ii/description/)
// TUF+ : Find Peak Element (https://takeuforward.org/plus/dsa/binary-search/2d-arrays/find-peak-element-ii)

/*
Topics and Learnings: Binary Search

Approach:
Used Binary Search to solve this

Complexity Analysis:
Complexity Analysis:
TC: O(M * logN)
SC: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> findPeakGrid(vector<vector<int>>& mat) {
		int n = mat.size();
		int m = mat[0].size();

		int low = 0, high = n - 1;
		while (low <= high) {
			int mid = (low + high) / 2;

			int col = max_element(mat[mid].begin(), mat[mid].end())
				- mat[mid].begin();
			int ele = mat[mid][col];

			int up = mid > 0 ? mat[mid - 1][col] : INT_MIN;
			int down = mid < n - 1 ? mat[mid + 1][col] : INT_MIN;

			if (ele > up && ele > down) return { mid, col };

			if (ele > up) low = mid + 1;
			else high = mid - 1;
		}

		return { -1, -1 };
	}
};

int main(int argc, const char** argv) {
	int t;
	cin >> t;

	while (t--) {
		int n, m;
		cin >> n >> m;

		vector<vector<int>> matrix;
		vector<int> arr;

		for (int i = 0; i < n; i++) {
			for (int i = 0; i < m; i++) {
				int input;
				cin >> input;
				arr.push_back(input);
			}
			matrix.push_back(arr);
			arr.clear();
		}

		Solution sol;

		vector<int> res = sol.findPeakGrid(matrix);

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

3 3
10 20 15
21 30 14
7 16 32

2 2
10 7
11 17

3 3
1 2 3
4 5 6
7 8 9

Test Output : 1
1 1
1 1
2 2

*/
