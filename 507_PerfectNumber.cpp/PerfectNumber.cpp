class Solution {
public:
	bool checkPerfectNumber(int num) {
		if (num <= 0) return false;
		int sum = 0;
		for (int i = 1; i * i <= num; i++) {
			if (num % i == 0) {
				sum += i;
				if (i != num / i)
					sum += num / i;
			}
		}
		return sum - num == num;
	}
};