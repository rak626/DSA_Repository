// Fractional Knapsack
#include <bits/stdc++.h>
class Knapsack {
public:
  int weight;
  int value;
  double valuePerWeight;
};
bool comparator(Knapsack s1, Knapsack s2) {
  return s1.valuePerWeight > s2.valuePerWeight;
}

double maximumValue(vector<pair<int, int>> &items, int n, int k) {
  Knapsack sacks[n];
  for (int i = 0; i < n; i++) {
    sacks[i].weight = items[i].first;
    sacks[i].value = items[i].second;
    sacks[i].valuePerWeight = (double)items[i].second / (double)items[i].first;
  }
  sort(sacks, sacks + n, comparator);
  double profit = 0.0;
  for (auto item : sacks) {
    if (k < item.weight) {
      profit += (double)k * item.valuePerWeight;
      break;
    }
    profit += item.value;
    k -= item.weight;
  }
  return profit;
}