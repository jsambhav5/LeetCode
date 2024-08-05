import java.util.Scanner;

public class MedianOfTwoSortedArrays {
	public static double findMedianSortedArrays(int[] nums1, int[] nums2) {
		int size1 = nums1.length;
		int size2 = nums2.length;
		int size = size1 + size2;

		if (size1 > size2)
			return findMedianSortedArrays(nums2, nums1);

		int low = 0;
		int high = size1;

		while (low <= high) {
			int mid1 = (low + high) / 2;
			int mid2 = ((size + 1) / 2) - mid1;

			int l1 = Integer.MIN_VALUE, l2 = Integer.MIN_VALUE;
			int r1 = Integer.MAX_VALUE, r2 = Integer.MAX_VALUE;

			if (mid1 >= 1)
				l1 = nums1[mid1 - 1];
			if (mid2 >= 1)
				l2 = nums2[mid2 - 1];
			if (mid1 < size1)
				r1 = nums1[mid1];
			if (mid2 < size2)
				r2 = nums2[mid2];

			if (l1 <= r2 && l2 <= r1) {
				if (size % 2 != 0)
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
		int size1, size2;

		Scanner sc = new Scanner(System.in);
		size1 = sc.nextInt();
		size2 = sc.nextInt();

		int[] nums1 = new int[size1];
		int[] nums2 = new int[size2];

		for (int i = 0; i < size1; i++) {
			nums1[i] = sc.nextInt();
		}

		for (int i = 0; i < size2; i++) {
			nums2[i] = sc.nextInt();
		}
		sc.close();

		double median = findMedianSortedArrays(nums1, nums2);
		System.out.println(median);
	}
}
