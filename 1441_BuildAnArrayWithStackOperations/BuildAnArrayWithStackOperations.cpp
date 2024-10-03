#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<string> buildArray(vector<int>& target, int n) {
		vector<string> result;
		if (target.empty())
			return result;
		for (int i = 1, j = 0; i <= target.back(); i++) {
			result.push_back("Push");
			if (i != target[j])
				result.push_back("Pop");
			else j++;
		}
		return result;
	}
};