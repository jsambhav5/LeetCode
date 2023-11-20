// Array Merge
/*
	1, 3, 8 = 3

	2, 4, 6, 12, 18, 19 = 9

	1, 2, 3, 4, 6, 8, 12, 18, 19 = 6
*/

public class MedianOfTwoSortedArray {
	static float findMedianOfTwoSortedArrays(int[] arr1, int[] arr2) {
		int size1 = arr1.length;
		int size2 = arr2.length;
		int total_size = size1 + size2;
		if (size1 > size2)
			return findMedianOfTwoSortedArrays(arr2, arr1);
		int low = 0, high = size1;
		while (low <= high) {
			int mid1 = (low + high) / 2;
			int mid2 = (total_size + 1 / 2) - mid1;
			int l1 = Integer.MIN_VALUE, l2 = Integer.MIN_VALUE;
			int r1 = Integer.MAX_VALUE, r2 = Integer.MAX_VALUE;
			if (mid1 < size1)
				r1 = arr1[mid1];
			if (mid1 >= 1)
				l1 = arr1[mid1 - 1];
			if (mid2 < size2)
				r2 = arr2[mid2];
			if (mid2 >= 1)
				l2 = arr2[mid2 - 1];
			if (l1 <= r2 && l2 <= r1) {
				if (total_size % 2 == 1)
					return Integer.max(l1, l2);
				return ((float) Integer.max(l1, l2) + Integer.min(r1, r2)) / 2;
			}
			if (l1 > r2)
				high = mid1 - 1;
			else
				low = mid1 + 1;
		}
		return 0;
	}

	public static void main(String[] args) {
		int[] arr1 = { 1, 3, 8 };
		int[] arr2 = { 2, 4, 6, 12, 18, 19 };
		float median = findMedianOfTwoSortedArrays(arr1, arr2);
		System.out.println(median);
	}
}
