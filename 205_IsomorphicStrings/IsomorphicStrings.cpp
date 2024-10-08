class Solution {
public:
	bool isIsomorphic(string s, string t) {
		int k = 0;
		unordered_map<char, int> mp1, mp2;
		for (int i = 0; i < s.length(); i++) {
			if (mp1.find(s[i]) == mp1.end()) {
				mp1[s[i]] = k;
				s[i] = 'A' + k;
				k++;
			}
			else s[i] = 'A' + mp1[s[i]];
		}
		k = 0;
		for (int i = 0; i < t.length(); i++) {
			if (mp2.find(t[i]) == mp2.end()) {
				mp2[t[i]] = k;
				t[i] = 'A' + k;
				k++;
			}
			else t[i] = 'A' + mp2[t[i]];
		}
		return s == t;
	}
};