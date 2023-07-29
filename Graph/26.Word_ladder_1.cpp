class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s(wordList.begin(), wordList.end());
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        s.erase(beginWord);
        while (q.size()) {
            string original = q.front().first;
            int level = q.front().second;
            q.pop();
            string cur = original;
            if (cur == endWord) return level;
            for (int j = 0; j < cur.size(); j++) {
                for (char k = 'a'; k <= 'z'; k++) {
                    cur[j] = k;
                    if (s.find(cur) != s.end()) {
                        s.erase(cur);
                        q.push({cur, level + 1});
                    }
                }
                cur = original;
            }
        }
        return 0;
    }
};