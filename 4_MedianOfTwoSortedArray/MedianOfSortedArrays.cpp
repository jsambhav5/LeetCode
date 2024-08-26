// Array Merge
/*
	1, 3, 8 = 3

	2, 4, 6, 12, 18 = 9

	1, 2, 3, 4, 6, 8, 12, 18 = 5
*/


#include<iostream>
#include<bits/stdc++.h>

using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	vector<int> arr;
	double result;
	int i = 0, j = 0;
	while (i < nums1.size() && j < nums2.size()) {
		if (nums1[i] <= nums2[j]) {
			arr.push_back(nums1[i++]);
		}
		else
			arr.push_back(nums2[j++]);
	}
	if (i < nums1.size())
		for (i; i < nums1.size(); i++)
			arr.push_back(nums1[i]);
	else if (j < nums2.size())
		for (j; j < nums2.size(); j++)
			arr.push_back(nums2[j]);
	if (arr.size() % 2 == 0)
		result = ((double)arr[arr.size() / 2] + (double)arr[arr.size() / 2 - 1]) / 2;

	else
		result = arr[(arr.size() - 1) / 2];

	return result;
}

int main(int argc, const char** argv) {
	int size1, size2, input;
	cin >> size1 >> size2;

	vector<int> nums1, nums2;

	for (int i = 0; i < size1; i++) {
		cin >> input;
		nums1.push_back(input);
	}

	for (int i = 0; i < size2; i++) {
		cin >> input;
		nums2.push_back(input);
	}

	cout << findMedianSortedArrays(nums1, nums2);
	return 0;
}