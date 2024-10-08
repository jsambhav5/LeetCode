class Solution {
public:
	bool isAnagram(string s, string t) {
		if (s.length() != t.length()) return false;
		unordered_map<char, int> mps, mpt;
		for (int i = 0; i < s.length(); i++)
			mps[s[i]]++;
		for (int i = 0; i < t.length(); i++)
			mpt[t[i]]++;
		for (auto i : mps)
			if (mpt[i.first] != i.second)
				return false;
		return true;
	}
};