// LeetCode : 48 - Rotate Image (https://leetcode.com/problems/rotate-image/)
// TUF+ : Rotate matrix by 90 degrees (https://takeuforward.org/plus/dsa/arrays/faqs-medium/rotate-matrix-by-90-degrees)

/*
	1 2 3 2				1 4 7 8 			8 7 4 1
	4 5 6 4		T=>		2 5 8 4		M=>		4 8 5 2		T - Transpose
	7 8 9 9				3 6 9 1				1 9 6 3		M - Mirror about middle y-axis
	8 4 1 4				2 4 9 4				4 9 4 2
*/

/*
Topics and Learnings:

Approach:
Clockwise Rotate by 90 = Transpose => Mirror by Y-axis

Complexity Analysis:
TC: O(N ^ 2)
SC: O(N ^ 2)
*/


#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
	void transpose(vector<vector<int>>& arr) {
		int n = arr.size();
		for (int i = 0; i < n; i++) {
			for (int j = i; j < n; j++) {
				swap(arr[i][j], arr[j][i]);
			}
		}
	}

	void mirrorY(vector<vector<int>>& arr) {
		int n = arr.size();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n / 2; j++) {
				swap(arr[i][j], arr[i][n - j - 1]);
			}
		}
	}

public:
	void rotate(vector<vector<int>>& arr) {
		transpose(arr);
		mirrorY(arr);
	}
};

int main(int argc, const char** argv) {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<vector<int>> matrix;

		for (int i = 0; i < n; i++) {
			vector<int> arr;
			for (int j = 0; j < n; j++) {
				int input;
				cin >> input;
				arr.push_back(input);
			}
			matrix.push_back(arr);
		}

		Solution sol;

		sol.rotate(matrix);

		for (auto i : matrix) {
			for (auto j : i) {
				cout << j << " ";
			}
			cout << endl;
		}

		cout << endl;
	}

	return 0;
}

/*
Test Input :
2

3
1 2 3
4 5 6
7 8 9

4
0 1 1 2
2 0 3 1
4 5 0 5
5 6 7 0

Test Output : 1
OUTPUT

*/
