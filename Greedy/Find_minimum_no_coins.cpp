// Find Minimum Number Of Coins
// Greedy

#include <bits/stdc++.h>
int findMinimumCoins(int amount) {
  vector<int> coin{1, 2, 5, 10, 20, 50, 100, 500, 1000};
  int cnt = 0;
  for (int i = coin.size() - 1; i >= 0; i--) {
    cnt += amount / coin[i];
    amount = amount % coin[i];
  }
  return cnt;
}