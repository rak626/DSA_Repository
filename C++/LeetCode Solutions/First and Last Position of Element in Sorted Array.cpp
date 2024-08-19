class Solution {
public:

    int leftbs(vector<int>& nums, int target){
        int l = 0, h = nums.size()-1;
        int last = -1;
        while(l <= h){
            int mid = l + (h - l) / 2;
            if(nums[mid] == target){
                last = mid;
                if(mid-1 >= 0 && nums[mid-1] == target){
                    h = mid-1;
                }else{
                    break;
                }
            }
            else if(nums[mid] < target) l = mid + 1;
            else h = mid -1;
        }
        return last;
    }
    int rightbs(vector<int>& nums, int target){
        int l = 0, h = nums.size()-1;
        int last = -1;
        while(l <= h){
            int mid = l + (h - l) / 2;
            if(nums[mid] == target){
                last = mid;
                if(mid+1 < nums.size() && nums[mid+1] == target){
                    l = mid+1;
                }else{
                    break;
                }
            }
            else if(nums[mid] < target) l = mid + 1;
            else h = mid -1;
        }
        return last;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        
        vector<int> ans(2);
        ans[0] = leftbs(nums,target);
        ans[1] = rightbs(nums,target);
        return ans;
    }
};








// ------------------nice solutions----------------------------

class Solution {
private:
    int lower_bound(vector<int>& nums, int low, int high, int target){
        while(low <= high){
            int mid = (low + high) >> 1;
            if(nums[mid] < target){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return low;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;
        int startingPosition = lower_bound(nums, low, high, target);
        int endingPosition = lower_bound(nums, low, high, target + 1) - 1;
        if(startingPosition < nums.size() && nums[startingPosition] == target){
            return {startingPosition, endingPosition};
        }
        return {-1, -1};
    }
};