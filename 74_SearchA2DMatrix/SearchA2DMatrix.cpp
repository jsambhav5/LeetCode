// LeetCode : 74 - Search a 2D Matrix (https://leetcode.com/problems/search-a-2d-matrix/description/)
// TUF+ : Search in a 2D Matrix (https://takeuforward.org/plus/dsa/binary-search/2d-arrays/search-in-a-2d-matrix)

/*
Topics and Learnings: Binary Search

Approach:
Since Matrix is sorted, used Binary search to search in the matrix

Complexiy Analysis:
TC: O(log(m * n))
SC: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int n = matrix.size();
		int m = matrix[0].size();
		int low = 0, high = (n * m) - 1;

		while (low <= high) {
			int mid = (low + high) / 2;
			int ele = matrix[mid / m][mid % m];

			if (ele == target) return true;
			if (ele < target) low = mid + 1;
			else high = mid - 1;
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
