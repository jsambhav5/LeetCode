class Solution {
private:
	static bool freqCompare(pair<int, char> p1, pair<int, char> p2) {
		if (p1.first > p2.first) return true;
		if (p1.first < p2.first) return false;
		return p1.second < p2.second;
	}

public:
	string frequencySort(string s) {
		pair<int, char> freq[128];
		for (int i = 0; i < 128; i++)
			freq[i] = { 0, (char)i };

		for (auto i : s)
			freq[i].first++;
		sort(freq, freq + 128, freqCompare);

		string ans;
		for (auto i : freq)
			for (int j = 0; j < i.first; j++)
				ans += i.second;
		return ans;
	}
};