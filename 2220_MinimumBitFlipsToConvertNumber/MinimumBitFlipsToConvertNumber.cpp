class Solution {
public:
	int minBitFlips(int start, int goal) {
		int temp = start ^ goal;
		int count = 0;
		for (int i = 0; i < 32; i++) {
			count += temp & 1;
			temp >>= 1;
		}
		return count;
	}
};