/*
 * Search.cc
 *
 *  Created on: Aug 29, 2022
 *      Author: Erwin
 */

#include "Search/Search.h"

template <typename T>
int binarySearch(T arr[], int n, T target) {
  // Find target in [l...r)
  int l = 0, r = n;
  // [l...r) is invalid when l == r
  while (l < r) {
    int mid = l + (r - l) << 1;
    if (target == arr[mid]) {
      return mid;
    }

    if (target > mid) {
      l = mid + 1;  // target exists in [mid + 1 ... r)
    } else {
      r = mid;  // target exists in [l ... mid)
    }
  }

  return -1;
}
