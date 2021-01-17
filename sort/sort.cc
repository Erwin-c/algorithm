/*
 * sort.cc
 *
 *  Created on: Jan 10, 2021
 *      Author: Erwin
 */

#include "sort.h"
#include <algorithm>
#include <iostream>

void SelectionSort(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    // Find the minimum in [i, n).
    int min_index = i;
    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[min_index]) {
        min_index = j;
      }
    }

    std::swap(arr[min_index], arr[i]);
  }
}

void InsertionSort(int arr[], int n) {
  for (int i = 1; i < n; i++) {
    // Find the insertion position of arr[i].
    for (int j = i; j > 0 && arr[j] < arr[j - 1]; j--) {
      if (arr[j] < arr[j - 1]) {
        std::swap(arr[j], arr[j - 1]);
      }
    }
  }
}
