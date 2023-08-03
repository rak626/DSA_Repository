class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s(wordList.begin(), wordList.end());
        queue<vector<string>> q;
        q.push({beginWord});
        vector<vector<string>> ans;
        vector<string> used{beginWord};
        int level = 0;

        while (q.size()) {
            vector<string> v = q.front();
            q.pop();

            if (v.size() > level) {
                for (auto it : used) {
                    s.erase(it);
                }
                level++;
                used.clear();
            }
            string word = v.back();
            if (word == endWord) {
                if (ans.size() == 0) {
                    ans.push_back(v);
                } else if (ans[0].size() == v.size()) {
                    ans.push_back(v);
                }
            }

            for (int i = 0; i < word.size(); i++) {
                char original = word[i];
                for (char k = 'a'; k <= 'z'; k++) {
                    word[i] = k;
                    if (s.count(word)) {
                        used.push_back(word);
                        v.push_back(word);
                        q.push(v);
                        v.pop_back();
                    }
                }
                word[i] = original;
            }
        }
        return ans;
    }
};

// optimised for leetcode
