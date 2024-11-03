class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int size1 = nums1.size();
		int size2 = nums2.size();

		if (size1 > size2) return findMedianSortedArrays(nums2, nums1);

		int size = size1 + size2;
		int left = (size + 1) / 2;

		int low = 0, high = size1;

		while (low <= size) {
			int mid1 = (low + high) / 2;
			int mid2 = left - mid1;

			int l1 = mid1 > 0 ? nums1[mid1 - 1] : INT_MIN;
			int l2 = mid2 > 0 ? nums2[mid2 - 1] : INT_MIN;
			int r1 = mid1 < size1 ? nums1[mid1] : INT_MAX;
			int r2 = mid2 < size2 ? nums2[mid2] : INT_MAX;

			if (l1 <= r2 && l2 <= r1) {
				if (size % 2 != 0) return max(l1, l2);
				return ((float)max(l1, l2) + min(r1, r2)) / 2;
			}

			if (l1 > r2) high = mid1 - 1;
			else low = mid1 + 1;
		}
		return 0;
	}
};