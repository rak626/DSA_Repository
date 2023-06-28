// Maximum activities

#include <bits/stdc++.h>
class Activity {
public:
    int start;
    int finish;
    int pos;
};
bool comparator(Activity a1, Activity a2) {
    if (a1.finish < a2.finish) return true;
    if (a1.finish == a2.finish) return a1.pos < a2.pos;
    return false;
}

int maximumActivities(vector<int> &start, vector<int> &finish) {
    int n = start.size();
    Activity act[start.size()];
    for (int i = 0; i < n; i++) {
        act[i].start = start[i];
        act[i].finish = finish[i];
        act[i].pos = i;
    }

    sort(act, act + n, comparator);
    int cnt = 0, prevFinish = 0;
    for (int i = 0; i < n; i++) {
        if (act[i].start >= prevFinish) {
            cnt++;
            prevFinish = act[i].finish;
        }
    }
    return cnt;
}