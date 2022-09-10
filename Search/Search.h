/*
 * Search.h
 *
 *  Created on: Aug 29, 2022
 *      Author: Erwin
 */

#ifndef SEARCH_H_
#define SEARCH_H_

namespace Search {

template <typename T>
int binarySearch(T arr[], int n, T target) {
  // Find target in arr[l...r)
  int l = 0, r = n;
  // arr[l...r) is invalid when 'l == r'
  while (l < r) {
    int mid = l + (r - l) << 1;
    if (target == arr[mid]) {
      return mid;
    }

    if (target > arr[mid]) {
      l = mid + 1;  // target exists in arr[(mid + 1)...r)
    } else {
      r = mid;  // target exists in arr[l...mid)
    }
  }

  return -1;
}

}  // namespace Search

#endif  // SEARCH_H_
