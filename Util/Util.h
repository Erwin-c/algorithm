/*
 * Util.h
 *
 *  Created on: Jan 10, 2021
 *      Author: Erwin
 */

#ifndef UTIL_H_
#define UTIL_H_

#include <cassert>
#include <iostream>
#include <string>

namespace Util {

// Generate a random array with n elements between [rangeLeft, rangeRight]
template <typename T>
T* generateRandomArray(int n, int rangeLeft, int rangeRight) {
  assert(rangeRight >= rangeLeft);

  T* arr = new T[n];
  srand(time(nullptr));
  for (int i = 0; i < n; ++i) {
    arr[i] = rand() % (rangeRight - rangeLeft + 1) + rangeLeft;
  }

  return arr;
}

// Generate an ordered array with n elements
template <typename T>
T* generateOrderedArray(int n) {
  T* arr = new T[n];
  for (int i = 0; i < n; ++i) {
    arr[i] = i;
  }

  return arr;
}

// Generate a nearly ordered array with n elements
template <typename T>
T* generateNearlyOrderedArray(int n, int swapTime) {
  T* arr = new T[n];
  for (int i = 0; i < n; ++i) {
    arr[i] = i;
  }

  srand(time(nullptr));
  for (int i = 0; i < swapTime; ++i) {
    int posx = rand() % n;
    int posy = rand() % n;
    std::swap(arr[posx], arr[posy]);
  }

  return arr;
}

template <typename T>
T* copyArray(T arr[], int n) {
  T* des = new T[n];
  std::copy(arr, arr + n, des);

  return des;
}

template <typename T>
bool isSorted(T arr[], int n) {
  for (int i = 0; i < n - 1; ++i) {
    if (arr[i + 1] < arr[i]) {
      return false;
    }
  }

  return true;
}

template <typename T>
void testSort(const std::string& sortName, void (*sort)(T[], T), T arr[],
              int n) {
  clock_t startTime = clock();
  sort(arr, n);
  clock_t endTime = clock();

  assert(isSorted(arr, n));

  std::cout << sortName << ": "
            << (double)(endTime - startTime) / CLOCKS_PER_SEC << "s"
            << std::endl;

  return;
}

template <typename T>
void printArray(T arr[], int n) {
  for (int i = 0; i < n; ++i) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;

  return;
}

}  // namespace Util

#endif  // UTIL_H_
