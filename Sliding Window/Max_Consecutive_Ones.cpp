// by sliding window technique
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt = 0, res = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i])
                cnt++;
            else {
                res = max(res, cnt);
                cnt = 0;
            }
        }
        if (cnt) res = max(res, cnt);
        return res;
    }
};

// T.C. -> O(n)
// S.C. -> O(1)