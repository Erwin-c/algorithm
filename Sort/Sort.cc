/*
 * Sort.cc
 *
 *  Created on: Jan 10, 2021
 *      Author: Erwin
 */

#include "Sort/Sort.h"

#include <algorithm>
#include <ctime>

#include "Heap/MaxHeap.h"

static void __insertionSort(int arr[], int l, int r);

static void __merge(int arr[], int l, int mid, int r);

static void __mergeSort(int arr[], int l, int r);

static void __mergeSortOptimized(int arr[], int l, int r);

static int __partition(int arr[], int l, int r);

static int __partitionOptimized(int arr[], int l, int r);

static int __partition2Ways(int arr[], int l, int r);

static void __quickSort(int arr[], int l, int r);

static void __quickSortOptimized(int arr[], int l, int r);

static void __quickSort2Ways(int arr[], int l, int r);

static void __quickSort3Ways(int arr[], int l, int r);

static void __insertionSort(int arr[], int l, int r) {
  for (int i = l + 1; i <= r; ++i) {
    int e = arr[i];
    int j;
    for (j = i; j > l && arr[j - 1] > e; --j) {
      arr[j] = arr[j - 1];
    }
    arr[j] = e;
  }

  return;
}

// Merge for arr[l...mid] and arr[mid + 1...r)
static void __merge(int arr[], int l, int mid, int r) {
  int aux[r - l + 1];
  for (int i = l; i <= r; ++i) {
    aux[i - l] = arr[i];
  }

  int i = l, j = mid + 1;
  for (int k = l; k <= r; ++k) {
    if (i > mid) {
      arr[k] = aux[j - l];
      ++j;
    } else if (j > r) {
      arr[k] = aux[i - l];
      ++i;
    } else if (aux[i - l] < aux[j - l]) {
      arr[k] = aux[i - l];
      ++i;
    } else {
      arr[k] = aux[j - l];
      ++j;
    }
  }

  return;
}

// Merge sort for arr[l...r]
static void __mergeSort(int arr[], int l, int r) {
  if (l >= r) {
    return;
  }

  int mid = l + (r - l) / 2;
  __mergeSort(arr, l, mid);
  __mergeSort(arr, mid + 1, r);
  __merge(arr, l, mid, r);

  return;
}

static void __mergeSortOptimized(int arr[], int l, int r) {
  // Optimation: There is a constant C in time complexity
  if (r - l <= 15) {
    __insertionSort(arr, l, r);
    return;
  }

  int mid = l + (r - l) / 2;
  __mergeSortOptimized(arr, l, mid);
  __mergeSortOptimized(arr, mid + 1, r);
  // Optimation: More important
  if (arr[mid] > arr[mid + 1]) {
    __merge(arr, l, mid, r);
  }

  return;
}

// Partition for arr[l...r]
// Return p: arr[l...(p - 1)] < arr[p], arr[(p + 1)...r] >= arr[p]
static int __partition(int arr[], int l, int r) {
  int v = arr[l];

  // arr[(l + 1)...j] < v, arr[(j + 1)...i) >= v
  int j = l;
  for (int i = l + 1; i <= r; ++i) {
    // Initial state throughout defination for internal
    // arr[(l + 1)...l] and arr[(l + 1)...(l + 1)) are both empty set
    if (arr[i] < v) {
      std::swap(arr[i], arr[++j]);
    }
  }
  std::swap(arr[j], arr[l]);

  return j;
}

static int __partitionOptimized(int arr[], int l, int r) {
  // Optimation: Avoid being O(n ^ 2) in ordered arrays
  srand(time(nullptr));
  std::swap(arr[l], arr[rand() % (r - l + 1) + l]);
  int v = arr[l];

  int j = l;
  for (int i = l + 1; i <= r; ++i) {
    if (arr[i] < v) {
      std::swap(arr[i], arr[++j]);
    }
  }
  std::swap(arr[j], arr[l]);

  return j;
}

static int __partition2Ways(int arr[], int l, int r) {
  srand(time(nullptr));
  std::swap(arr[l], arr[rand() % (r - l + 1) + l]);
  int v = arr[l];

  // arr[(l + 1)...i) <= v; arr(j...r] >= v
  int i = l + 1, j = r;
  while (true) {
    // Why not arr[i] <= v?
    while (i <= r && arr[i] < v) {
      ++i;
    }
    // Why not arr[j] >= v?
    while (j >= l + 1 && arr[j] > v) {
      --j;
    }

    // Ref: http://coding.imooc.com/learn/questiondetail/4920.html

    if (i > j) {
      break;
    }

    std::swap(arr[i++], arr[j--]);
  }

  std::swap(arr[j], arr[l]);

  return j;
}

// Quick sort for arr[l...r]
static void __quickSort(int arr[], int l, int r) {
  if (r - l <= 15) {
    __insertionSort(arr, l, r);
    return;
  }

  int p = __partition(arr, l, r);
  __quickSort(arr, l, p - 1);
  __quickSort(arr, p + 1, r);

  return;
}

static void __quickSortOptimized(int arr[], int l, int r) {
  if (r - l <= 15) {
    __insertionSort(arr, l, r);
    return;
  }

  int p = __partitionOptimized(arr, l, r);
  __quickSortOptimized(arr, l, p - 1);
  __quickSortOptimized(arr, p + 1, r);

  return;
}

static void __quickSort2Ways(int arr[], int l, int r) {
  if (r - l <= 15) {
    __insertionSort(arr, l, r);
    return;
  }

  int p = __partition2Ways(arr, l, r);
  __quickSort2Ways(arr, l, p - 1);
  __quickSort2Ways(arr, p + 1, r);

  return;
}

static void __quickSort3Ways(int arr[], int l, int r) {
  if (r - l <= 15) {
    __insertionSort(arr, l, r);
    return;
  }

  srand(time(nullptr));
  std::swap(arr[l], arr[rand() % (r - l + 1) + l]);
  int v = arr[l];

  int lt = l;      // arr[(l + 1)...lt] < v
  int gt = r + 1;  // arr[gt...r] > v
  int i = l + 1;   // arr[(lt + 1)...i) == v
  while (i < gt) {
    if (arr[i] < v) {
      std::swap(arr[i], arr[lt + 1]);
      ++i;
      ++lt;
    } else if (arr[i] > v) {
      std::swap(arr[i], arr[gt - 1]);
      --gt;
    } else {  // arr[i] == v
      ++i;
    }
  }

  std::swap(arr[l], arr[lt]);

  __quickSort3Ways(arr, l, lt - 1);
  __quickSort3Ways(arr, gt, r);

  return;
}

void selectionSort(int arr[], int n) {
  for (int i = 0; i < n; ++i) {
    // Find the minimum in [i, n)
    int minIndex = i;
    for (int j = i + 1; j < n; ++j) {
      if (arr[j] < arr[minIndex]) {
        minIndex = j;
      }
    }

    std::swap(arr[minIndex], arr[i]);
  }

  return;
}

void insertionSort(int arr[], int n) {
  for (int i = 1; i < n; ++i) {
    // Find the insertion position of arr[i]
    // Optimation compared with std::swap()
    int e = arr[i];
    int j;
    for (j = i; j > 0 && arr[j - 1] > e; --j) {
      arr[j] = arr[j - 1];
    }
    arr[j] = e;
  }

  return;
}

void mergeSort(int arr[], int n) {
  __mergeSort(arr, 0, n - 1);
  return;
}

void mergeSortOptimized(int arr[], int n) {
  __mergeSortOptimized(arr, 0, n - 1);
  return;
}

void quickSort(int arr[], int n) {
  __quickSort(arr, 0, n - 1);
  return;
}

void quickSortOptimized(int arr[], int n) {
  __quickSortOptimized(arr, 0, n - 1);
  return;
}

void quickSort2Ways(int arr[], int n) {
  __quickSort2Ways(arr, 0, n - 1);
  return;
}

void quickSort3Ways(int arr[], int n) {
  __quickSort3Ways(arr, 0, n - 1);
  return;
}

// Create a heap using Insert -> O(nlogn)
// Sort using Exract -> O(nlogn)
// heapSort1 -> O(nlogn)
void heapSort1(int arr[], int n) {
  MaxHeap<int> maxheap = MaxHeap<int>(n);
  for (int i = 0; i < n; ++i) {
    maxheap.insert(arr[i]);
  }

  for (int i = n - 1; i >= 0; --i) {
    arr[i] = maxheap.extractMax();
  }

  return;
}

// Optimization: Create a heap using Heapify -> O(n)
// Sort using Exract -> O(nlogn)
// heapSort2 -> O(nlogn) but optimized
void heapSort2(int arr[], int n) {
  MaxHeap<int> maxheap = MaxHeap<int>(arr, n);

  for (int i = n - 1; i >= 0; --i) {
    arr[i] = maxheap.extractMax();
  }

  return;
}
