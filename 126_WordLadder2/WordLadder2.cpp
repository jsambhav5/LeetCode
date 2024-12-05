class Solution {
private:
    void dfs(string word, string &beginWord, vector<string> &seq, unordered_map <string,int> &mpp, vector<vector<string>> &ans) {
        
        if(word == beginWord) {
            reverse(seq.begin(), seq.end());
            ans.push_back(seq);
            reverse(seq.begin(), seq.end());
            return;
        }
        
        int val = mpp[word];
        
        for(int i=0; i < word.length(); i++) {
            char original = word[i];
            
            for(char ch = 'a'; ch <= 'z'; ch++) {
                word[i] = ch;
                
                if(mpp.find(word) != mpp.end() && 
                    mpp[word] + 1 == val) {
                    seq.push_back(word);
                    dfs(word, beginWord, seq, mpp, ans);
                    seq.pop_back();
                }
            }
            word[i] = original;
        }
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        int len = beginWord.length();
        unordered_set <string> st(wordList.begin(), wordList.end());
        unordered_map <string,int> mpp;
        queue <string> q;
        
        q.push(beginWord);
        st.erase(beginWord);
        
        int steps = 1;
        mpp[beginWord] = steps;
        
        while(!q.empty()) {
            string word = q.front();
            steps = mpp[word];
            q.pop();
            
            for(int i = 0; i < len; i++) {
                char original = word[i];
                
                for(char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;
                    
                    if(st.find(word) != st.end()) {
                        mpp[word] = steps+1;
                        q.push(word);
                        st.erase(word);
                    }
                }
                word[i] = original;
            }
        }

        if(mpp.find(endWord) == mpp.end()) return {};

        vector<vector<string>> ans;
        vector <string> seq = {endWord};
        dfs(endWord, beginWord, seq, mpp, ans);
        
        return ans;
    }
};
