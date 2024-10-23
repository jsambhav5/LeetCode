// LeetCode : 439 - Reverse Pairs (https://leetcode.com/problems/reverse-pairs)
// TUF+ : Reverse Pairs (https://takeuforward.org/plus/data-structures-and-algorithm/arrays/faqs-hard/reverse-pairs)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int reversePairs(vector<int>& nums) {
		int n = nums.size();
		return team(nums, n);
	}

private:
	void merge(vector<int>& arr, int low, int mid, int high) {
		vector<int> temp;

		int left = low;
		int right = mid + 1;

		while (left <= mid && right <= high) {
			if (arr[left] <= arr[right]) {
				temp.push_back(arr[left]);
				left++;
			}
			else {
				temp.push_back(arr[right]);
				right++;

			}
		}

		while (left <= mid) {
			temp.push_back(arr[left]);
			left++;
		}

		while (right <= high) {
			temp.push_back(arr[right]);
			right++;
		}

		for (int i = low; i <= high; i++) {
			arr[i] = temp[i - low];
		}
	}

private:
	int countPairs(vector<int>& arr, int low, int mid, int high) {
		int right = mid + 1;
		int cnt = 0;

		for (int i = low; i <= mid; i++) {
			while (right <= high && arr[i] > 2 * arr[right]) right++;
			cnt += (right - (mid + 1));
		}
		return cnt;
	}

private:
	int mergeSort(vector<int>& arr, int low, int high) {
		int cnt = 0;

		if (low >= high) {
			return cnt;
		}
		int mid = low + (high - low) / 2;
		cnt += mergeSort(arr, low, mid);
		cnt += mergeSort(arr, mid + 1, high);
		cnt += countPairs(arr, low, mid, high);

		merge(arr, low, mid, high);

		return cnt;
	}

private:
	int team(vector <int>& skill, int n) {
		return mergeSort(skill, 0, n - 1);
	}
};

int main() {
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

		int ans = sol.reversePairs(arr);

		cout << ans << endl;
	}

	return 0;
}

/*
Test Input : 
4
5
6 4 1 2 7
5 
5 4 4 3 3
5
2 4 3 5 1
5
1 3 2 3 1

Test Output : 1
3
0
3
2

*/ 