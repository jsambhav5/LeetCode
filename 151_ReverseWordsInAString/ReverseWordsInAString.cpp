class Solution {
public:
    string reverseWords(string s) {
        int i = -1, j = 0;
        while(j < s.length()) {
            i++;
            while(s[j] == ' ' && j < s.length()) j++;

            while(s[j] != ' ' && j < s.length()) {
                s[i++] = s[j++];
            }
            s[i] = ' ';
        }
        
        while(s[i] == ' ') i--;

        s = s.substr(0, i + 1);
        
        reverse(s.begin(), s.end());
        auto start = s.begin();
        for(int i = 0; i <= s.length(); i++) {
            if(i == s.length() || s[i] == ' ') {
                reverse(start, s.begin() + i);
                start = s.begin() + i + 1;
            }
        }
        while(j < s.length()) {
            while(s[j] == ' ' && j < s.length()) j++;

            while(s[j] != ' ' && j < s.length()) {
                s[i++] = s[j++];
            }
            s[i++] = ' ';
        }
        return s;
    }
};
