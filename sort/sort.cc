/*
 * sort.cc
 *
 *  Created on: Jan 10, 2021\
 *      Author: Erwin
 */

#include "sort/sort.h"

#include <algorithm>
#include <ctime>

namespace sort {

static void InsertionSort(int arr[], int l, int r);

static void Merge(int arr[], int l, int mid, int r);
static void MergeSort(int arr[], int l, int r);
static void MergeSortAdvanced(int arr[], int l, int r);

static int Partition(int arr[], int l, int r);
static int PartitionAdvanced(int arr[], int l, int r);
static void QuickSort(int arr[], int l, int r);
static void QuickSortAdvanced(int arr[], int l, int r);

static void InsertionSort(int arr[], int l, int r) {
  for (int i = l + 1; i <= r; i++) {
    int e = arr[i];
    int j;
    for (j = i; j > l && arr[j - 1] > e; j--) {
      arr[j] = arr[j - 1];
    }
    arr[j] = e;
  }
}

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

  int mid = l + (r - l) / 2;
  MergeSort(arr, l, mid);
  MergeSort(arr, mid + 1, r);
  Merge(arr, l, mid, r);
}

static void MergeSortAdvanced(int arr[], int l, int r) {
  // Optimation: There is a constant C in time complexity.
  if (r - l <= 15) {
    InsertionSort(arr, l, r);
    return;
  }

  int mid = l + (r - l) / 2;
  MergeSortAdvanced(arr, l, mid);
  MergeSortAdvanced(arr, mid + 1, r);
  // Optimation: More important.
  if (arr[mid] > arr[mid + 1]) {
    Merge(arr, l, mid, r);
  }
}

// Partition for arr[l...r].
// Return p: arr[l...(p - 1)] < arr[p], arr[(p + 1)...r] >= arr[p].
static int Partition(int arr[], int l, int r) {
  int v = arr[l];

  // arr[(l + 1)...j] < v, arr[(j + 1)...i) >= v.
  int j = l;
  for (int i = l + 1; i <= r; i++) {
    // Initial state throughout defination for internal.
    // arr[(l + 1)...l] and arr[(l + 1)...(l + 1)) are both empty set.
    if (arr[i] < v) {
      std::swap(arr[i], arr[++j]);
    }
  }
  std::swap(arr[j], arr[l]);

  return j;
}

static int PartitionAdvanced(int arr[], int l, int r) {
  // Optimation: Avoid being O(n ^ 2) in ordered arrays.
  srand(time(nullptr));
  std::swap(arr[l], arr[rand() % (r - l + 1) + l]);
  int v = arr[l];

  int j = l;
  for (int i = l + 1; i <= r; i++) {
    if (arr[i] < v) {
      std::swap(arr[i], arr[++j]);
    }
  }
  std::swap(arr[j], arr[l]);

  return j;
}

// Quick sort for arr[l...r].
static void QuickSort(int arr[], int l, int r) {
  if (r - l <= 15) {
    InsertionSort(arr, l, r);
    return;
  }

  int p = Partition(arr, l, r);
  QuickSort(arr, l, p - 1);
  QuickSort(arr, p + 1, r);
}

static void QuickSortAdvanced(int arr[], int l, int r) {
  if (r - l <= 15) {
    InsertionSort(arr, l, r);
    return;
  }

  int p = PartitionAdvanced(arr, l, r);
  QuickSortAdvanced(arr, l, p - 1);
  QuickSortAdvanced(arr, p + 1, r);
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
    // Optimation compared with std::swap().
    int e = arr[i];
    int j;
    for (j = i; j > 0 && arr[j - 1] > e; j--) {
      arr[j] = arr[j - 1];
    }
    arr[j] = e;
  }
}

void MergeSort(int arr[], int n) { MergeSort(arr, 0, n - 1); }

void MergeSortAdvanced(int arr[], int n) { MergeSortAdvanced(arr, 0, n - 1); }

void QuickSort(int arr[], int n) { QuickSort(arr, 0, n - 1); }

void QuickSortAdvanced(int arr[], int n) { QuickSortAdvanced(arr, 0, n - 1); }

}  // namespace sort
