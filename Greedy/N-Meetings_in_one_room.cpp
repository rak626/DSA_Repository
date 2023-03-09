// N meetings in one room or Maximum meetings
#include <bits/stdc++.h>
class meeting {
public:
  int start;
  int end;
  int pos;
};

bool comparator(meeting m1, meeting m2) {
  if (m1.end < m2.end)
    return 1;
  else if (m1.end > m2.end)
    return 0;
  else if (m1.pos < m2.pos)
    return 1;
  return 0;
}

vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
  vector<int> ans;
  int n = start.size();
  meeting meet[n];
  for (int i = 0; i < n; i++) {
    meet[i].start = start[i];
    meet[i].end = end[i];
    meet[i].pos = i + 1;
  }
  sort(meet, meet + n, comparator);
  int prevEnd = meet[0].end;
  ans.push_back(meet[0].pos);
  for (int i = 1; i < n; i++) {
    if (meet[i].start > prevEnd) {
      prevEnd = meet[i].end;
      ans.push_back(meet[i].pos);
    }
  }
  return ans;
}