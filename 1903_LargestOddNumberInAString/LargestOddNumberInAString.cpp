class Solution {
public:
	string largestOddNumber(string num) {
		int lastOddDigitIndex = -1, mostSignificantBit = 0;
		for (int i = num.length() - 1; i >= 0; i--) {
			if ((num[i] - '0') % 2 == 1) {
				lastOddDigitIndex = i;
				break;
			}
		}
		for (; mostSignificantBit < lastOddDigitIndex; mostSignificantBit++) {
			if (num[mostSignificantBit] != '0')
				break;
		}
		return num.substr(mostSignificantBit, lastOddDigitIndex - mostSignificantBit + 1);
	}
};