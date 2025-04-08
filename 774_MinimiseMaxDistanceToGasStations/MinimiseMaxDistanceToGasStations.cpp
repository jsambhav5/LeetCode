// LeetCode : 774 - Minimize Max Distance to Gas Station (https://leetcode.com/problems/minimize-max-distance-to-gas-station)
// TUF+ : Minimise max distance to gas stations (https://takeuforward.org/plus/dsa/binary-search/faqs/minimise-max-distance-to-gas-stations)

/*
Topics and Learnings: Binary Search

Approach:
Used Binary Search to solve this

Complexity Analysis:
TC: O(N*log(Len)) + O(N)
SC: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
	int numberOfGasStationsRequired(long double dist, vector<int>& arr) {
		int n = arr.size();
		int cnt = 0;
		for (int i = 1; i < n; i++) {
			int numberInBetween = ((arr[i] - arr[i - 1]) / dist);
			if ((arr[i] - arr[i - 1]) == (dist * numberInBetween)) {
				numberInBetween--;
			}
			cnt += numberInBetween;
		}
		return cnt;
	}
public:
	long double minimiseMaxDistance(vector<int>& arr, int k) {
		int n = arr.size();
		long double low = 0;
		long double high = 0;

		for (int i = 0; i < n - 1; i++) {
			high = max(high, (long double)(arr[i + 1] - arr[i]));
		}

		long double diff = 1e-6;
		while (high - low > diff) {
			long double mid = (low + high) / 2.0;
			int cnt = numberOfGasStationsRequired(mid, arr);

			if (cnt > k) {
				low = mid;
			}
			else {
				high = mid;
			}
		}

		return high;
	}
};

int main(int argc, const char** argv) {
	int t;
	cin >> t;

	while (t--) {
		int n, k;
		cin >> n >> k;

		vector<int> arr;

		for (int i = 0; i < n; i++) {
			int input;
			cin >> input;
			arr.push_back(input);
		}

		Solution sol;

		long double res = sol.minimiseMaxDistance(arr, k);
		cout << res << endl;
	}

	return 0;
}

/*
Test Input :
3

10 10
1 2 3 4 5 6 7 8 9 10

10 1
1 2 3 4 5 6 7 8 9 10

10 2
3 6 12 19 33 44 67 72 89 95

Test Output : 1
0.5
1
14

*/
