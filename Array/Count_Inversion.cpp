/*===================================
Count Inversion
===================================*/


#include <bits/stdc++.h>

void merge(long long *arr, long long *temp, int s, int mid, int e,
           long long int &cnt) {
  int i = s;
  int j = mid + 1;
  int k = s;
  while (i <= mid && j <= e) {
    if (arr[i] <= arr[j]) {
      temp[k++] = arr[i++];
    } else {
      temp[k++] = arr[j++];
      cnt += (mid - i + 1);
    }
  }
  while (i <= mid) {
    temp[k++] = arr[i++];
  }
  while (j <= e) {
    temp[k++] = arr[j++];
  }
  // copying temp elements  back to the array
  for (int i = s; i <= e; i++)
    arr[i] = temp[i];
}
void mergesort(long long *arr, long long *temp, int s, int e,
               long long int &cnt) {
  if (s >= e)
    return;
  int mid = s + (e - s) / 2;
  mergesort(arr, temp, s, mid, cnt);
  mergesort(arr, temp, mid + 1, e, cnt);
  merge(arr, temp, s, mid, e, cnt);
}

long long getInversions(long long *arr, int n) {
  // Write your code here.
  long long int cnt = 0;
  long long temp[n];
  mergesort(arr, temp, 0, n - 1, cnt);
  return cnt;
}