// LeetCode : 240 - Search a 2D Matrix II (https://leetcode.com/problems/search-a-2d-matrix-ii/description/)
// TUF+ : Search in 2D matrix - II (https://takeuforward.org/plus/dsa/binary-search/2d-arrays/search-in-2d-matrix-ii)

/*
Topics and Learnings: Binary Search

Approach:
Started with the upper right corner
if element == target, return true
if element > target, col--
else row++

Complexity Analysis:
TC: O(m + n))
SC: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int n = matrix.size();
		int m = matrix[0].size();

		int row = 0, col = m - 1;

		while (row < n && col >= 0) {
			if (matrix[row][col] == target) return true;
			if (matrix[row][col] > target) col--;
			else row++;
		}

		return false;
	}
};

int main(int argc, const char** argv) {
	int t;
	cin >> t;

	while (t--) {
		int target, n, m;
		cin >> target >> n >> m;

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
		bool res = sol.searchMatrix(matrix, target);
		cout << res << endl;
	}

	return 0;
}

/*
Test Input :
5

3 3 4
1 3 5 7
10 11 16 20
23 30 34 60

13 3 4
1 3 5 7
10 11 16 20
23 30 34 60

8 3 4
1 2 3 4
5 6 7 8
9 10 11 12

78 3 3
1 2 4
6 7 8
9 10 34

7 3 3
1 2 4
6 7 8
9 10 34

Test Output : 1
1
0
1
0
1

*/
