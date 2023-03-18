class Solution {
public:
  void reverse(vector<int> &nums, int s, int e) {
    while (s <= e) {
      swap(nums[s++], nums[e--]);
    }
  }
  void nextPermutation(vector<int> &nums) {
    int idx1 = -1, n = nums.size();
    for (int i = n - 2; i >= 0; i--) {
      if (nums[i] < nums[i + 1]) {
        idx1 = i;
        break;
      }
    }
    if (idx1 >= 0) {
      for (int i = n - 1; i > idx1; i--) {
        if (nums[i] > nums[idx1]) {
          swap(nums[idx1], nums[i]);
          break;
        }
      }
    }
    reverse(nums, idx1 + 1, n - 1);
  }
};