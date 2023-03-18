/*===================
Reverse Pairs
==================*/

// by modified margesort

#include <bits/stdc++.h>

void merge(vector<int> &arr, vector<int> &temp, int l, int mid, int h,
           int &cnt) {
  int i = l, j = mid + 1, k = l;

  while (i <= mid and j <= h) {
    if (arr[i] > 2 * arr[j]) {
      cnt += mid - i + 1;
      j++;
    } else {
      i++;
    }
  }
  i = l, j = mid + 1;
  while (i <= mid and j <= h) {
    if (arr[i] <= arr[j]) {
      temp[k++] = arr[i++];
    } else {
      temp[k++] = arr[j++];
    }
  }
  while (i <= mid) {
    temp[k++] = arr[i++];
  }
  while (j <= h) {
    temp[k++] = arr[j++];
  }
  for (i = l; i <= h; i++) {
    arr[i] = temp[i];
  }
}

void mergesort(vector<int> &arr, vector<int> &temp, int l, int h, int &cnt) {
  if (h > l) {
    int mid = l + (h - l) / 2;
    mergesort(arr, temp, l, mid, cnt);
    mergesort(arr, temp, mid + 1, h, cnt);
    merge(arr, temp, l, mid, h, cnt);
  }
}

int reversePairs(vector<int> &arr, int n) {
  int cnt = 0;
  vector<int> temp(n, 0);
  mergesort(arr, temp, 0, n - 1, cnt);
  return cnt;
}