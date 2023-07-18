// Search in Rotated Sorted Array

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        while (low <= high) {
            int mid = (low + high) >> 1;
            if (nums[mid] == target) return mid;
            // left side sorted
            if (nums[low] <= nums[mid]) {
                if (target >= nums[low] and target <= nums[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else {
                if (target >= nums[mid] and target <= nums[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};

// Time Complexity - log n;
// Space Complexity - O(1);