/*
 * sort.cc
 *
 *  Created on: Jan 10, 2021
 *      Author: Erwin
 */

#include "sort.h"

#include <algorithm>

namespace sort {

static void Merge(int arr[], int l, int mid, int r);
static void MergeSort(int arr[], int l, int r);

// Merge for arr[l...mid] and arr[mid + 1...r).
static void Merge(int arr[], int l, int mid, int r) {
  int aux[r - l + 1];
  for (int i = l; i <= r; i++) {
    aux[i - l] = arr[i];
  }

  int i = l, j = mid + 1;
  for (int k = l; k <= r; k++) {
    if (i > mid) {
      arr[k] = aux[j - l];
      j++;
    } else if (j > r) {
      arr[k] = aux[i - l];
      i++;
    } else if (aux[i - l] < aux[j - l]) {
      arr[k] = aux[i - l];
      i++;
    } else {
      arr[k] = aux[j - l];
      j++;
    }
  }
}

// Merge sort for arr[l...r].
static void MergeSort(int arr[], int l, int r) {
  if (l >= r) {
    return;
  }

  int mid = (l + r) / 2;
  MergeSort(arr, l, mid);
  MergeSort(arr, mid + 1, r);
  Merge(arr, l, mid, r);
}

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

void MergeSort(int arr[], int n) { MergeSort(arr, 0, n - 1); }

}  // namespace sort
