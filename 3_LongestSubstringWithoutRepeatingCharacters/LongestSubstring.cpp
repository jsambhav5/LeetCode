// No Repeating Character
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
	map<char, int> pos;
	int result = 0, begin = -1;
	for (int i = 0; i < s.length(); i++) {
		if (!pos[s[i]] || begin >= pos[s[i]])
			result = max(result, i - begin);
		else
			begin = pos[s[i]] - 1;
		pos[s[i]] = i + 1;
	}
	return result;
}

int main(int argc, const char** argv) {
	// string s = "tmmzuxt";
	string s = "abcabcbb";
	cout << lengthOfLongestSubstring(s);
	return 0;
}