import java.util.HashMap;
import java.util.Scanner;

public class TwoSum {
	public static int[] twoSum(int[] nums, int target) {
		HashMap<Integer, Integer> counter = new HashMap<>();
		for (int i = 0; i< nums.length; i++) {
			if(counter.get(target - nums[i]) != null) 
				return new int[] {counter.get(target - nums[i]), i};
			counter.put(nums[i], i);
		}
		return new int[]{};
	}
		public static void main (String[] args) {
		int size, target;
		Scanner sc = new Scanner(System.in);  
		size = sc.nextInt();
		int[] nums = new int[size];
		for (int i = 0; i< size; i++) {
			nums[i] = sc.nextInt();
		}
		target = sc.nextInt();
		sc.close();
		for (int i = 0; i< 2; i++) {
			System.out.println(twoSum(nums, target)[i]);		
		}
	}
}
