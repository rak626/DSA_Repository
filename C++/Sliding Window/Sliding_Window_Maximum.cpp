//-------------------------------------------
// heap solution by max heap
//-------------------------------------------
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int, int>> pq;
        vector<int> ans;

        for (int i = 0; i < k; i++) {
            pq.push({nums[i], i});
        }

        ans.push_back(pq.top().first);
        // create window
        for (int i = k; i < n; i++) {
            while (!pq.empty() && pq.top().second <= (i - k)) {
                pq.pop();
            }
            pq.push({nums[i], i});
            ans.push_back(pq.top().first);
        }
        return ans;
    }
};

// T.C. -> O(n log k)
// S.C. -> O(k)

// --------------------------------------
// dequeue Solution (monotonic decreasing dequeue)
// --------------------------------------

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;  // it will store only indices.
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            // if window already of k size , then remove the first element
            if (dq.size() && dq.front() == i - k) dq.pop_front();

            // make decreasing monotonic queue
            while (dq.size() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);

            // check if k size window is there , if yes then push the dq's front value as ans
            if (i >= k - 1) {
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};

// T.C. -> O(n)
// S.C. -> O(n)
