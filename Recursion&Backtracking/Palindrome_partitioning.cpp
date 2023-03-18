// Palindrome Partitioning

bool isPalindrome(string res) {
  int s = 0, e = res.size() - 1;
  while (s <= e) {
    if (res[s] != res[e])
      return 0;
    s++, e--;
  }
  return 1;
}

void findPartition(string &s, int idx, vector<string> &ds,
                   vector<vector<string>> &ans) {
  if (idx == s.size()) {
    ans.push_back(ds);
    return;
  }

  for (int i = idx; i < s.size(); i++) {
    string res = s.substr(idx, i - idx + 1);
    if (isPalindrome(res)) {
      ds.push_back(res);
      findPartition(s, i + 1, ds, ans);
      ds.pop_back();
    }
  }
}

vector<vector<string>> partition(string &s) {
  vector<vector<string>> ans;
  vector<string> ds;
  findPartition(s, 0, ds, ans);
  return ans;
}