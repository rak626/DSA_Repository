// Remove Duplicates from Sorted Array

// brute force will be using set

// optimized

int removeDuplicates(vector<int> &arr, int n) {
  if (n <= 1)
    return n;
  int i = 0, j = 0;
  while (i < n and j < n) {
    if (arr[i] != arr[j]) {
      arr[++i] = arr[j];
    }
    j++;
  }
  return i + 1;
}
