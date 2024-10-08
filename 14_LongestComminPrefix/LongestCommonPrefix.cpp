class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		string res = "";
		bool flag = true;
		for (int i = 0; i < strs[0].size(); i++) {
			for (int j = 1; j < strs.size(); j++) {
				if (strs[j][i] != strs[0][i]) {
					flag = false;
					break;
				}
			}
			if (flag) res += strs[0][i];
			else break;
		}
		return res;
	}
};