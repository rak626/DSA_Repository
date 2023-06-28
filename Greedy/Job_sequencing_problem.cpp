// Job Sequencing Problem
#include <bits/stdc++.h>
bool comparator(vector<int> job1, vector<int> job2) {
    return (job1[1] > job2[1]);
}

int jobScheduling(vector<vector<int>> &jobs) {
    int profit = 0;
    sort(jobs.begin(), jobs.end(), comparator);
    int maxDead = 0;
    for (auto job : jobs) {
        maxDead = max(maxDead, job[0]);
    }
    vector<int> sch(maxDead + 1, -1);

    for (int i = 0; i < jobs.size(); i++) {
        for (int j = jobs[i][0]; j > 0; j--) {
            if (sch[j] == -1) {
                profit += jobs[i][1];
                sch[j] = 1;
                break;
            }
        }
    }
    return profit;
}