class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int min = prices[0];
    int n = prices.size();
    int best = 0;
    for (int i = 1; i < n; i++) {
      if (prices[i] < min) {
        min = prices[i];
      } else {
        best = max(best, prices[i] - min);
      }
    }
    return best;
  }
};