// LeetCode : 118 - Pascal's Triangle (https://leetcode.com/problems/pascals-triangle/description/)
// TUF+ : Pascal's Triangle (https://takeuforward.org/plus/dsa/arrays/faqs-medium/pascal's-triangle)

/*
Topics and Learnings:

Approach:
pascal[i][j] = pascal[i - 1][j] + pascal[i - 1][j - 1]

Complexiy Analysis:
TC: O(N ^ 2)
SC: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<int> init(1, 1);
		vector<vector<int>> pascal(numRows, init);

		for (int i = 1; i < numRows; i++) {
			for (int j = 0; j < i - 1; j++) {
				pascal[i].push_back(pascal[i - 1][j] + pascal[i - 1][j + 1]);
			}
			pascal[i].push_back(1);
		}

		return pascal;
	}
};

int main(int argc, const char** argv) {
	int t;
	cin >> t;

	while (t--) {
		int numRows;
		cin >> numRows;

		Solution sol;
		vector<vector<int>> res = sol.generate(numRows);

		for (auto i : res) {
			for (auto j : i) {
				cout << j << " ";
			}
			cout << endl;
		}

		cout << endl << endl;
	}

	return 0;
}

/*
Test Input :
3

4
5
3

Test Output : 1
1
1 1
1 2 1
1 3 3 1


1
1 1
1 2 1
1 3 3 1
1 4 6 4 1


1
1 1
1 2 1

*/
