// Matrix Median

int countSmallerOrEqualToMid(vector<int> &row, int key) {
  int low = 0;
  int high = row.size() - 1;
  while (low <= high) {
    int md = (low + high) >> 1;
    if (row[md] <= key) {
      low = md + 1;
    } else {
      high = md - 1;
    }
  }
  return low;
}

int getMedian(vector<vector<int>> &matrix) {
  int n = matrix.size();
  int m = matrix[0].size();
  int low = 1;
  int high = 1e9;

  while (low <= high) {

    int mid = (low + high) >> 1; // divide by 2
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      cnt += countSmallerOrEqualToMid(matrix[i], mid);
    }
    if (cnt <= (n * m) / 2) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return low;
}

// Time Complexity - log2(2^32) * n * log2(m) = 32 * n log m
// Space Complexity - O(1);
