/*
 * Util.cc
 *
 *  Created on: Jan 10, 2021
 *      Author: Erwin
 */

#include "Util/Util.h"

#include <cassert>
#include <iostream>

namespace Util {

int* generateRandomArray(int n, int rangeLeft, int rangeRight) {
  assert(rangeRight >= rangeLeft);

  int* arr = new int[n];
  srand(time(nullptr));
  for (int i = 0; i < n; ++i) {
    arr[i] = rand() % (rangeRight - rangeLeft + 1) + rangeLeft;
  }

  return arr;
}

int* generateOrderedArray(int n) {
  int* arr = new int[n];
  for (int i = 0; i < n; ++i) {
    arr[i] = i;
  }

  return arr;
}

int* generateNearlyOrderedArray(int n, int swapTime) {
  int* arr = new int[n];
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

int* copyArray(int arr[], int n) {
  int* des = new int[n];
  std::copy(arr, arr + n, des);

  return des;
}

bool isSorted(int arr[], int n) {
  for (int i = 0; i < n - 1; ++i) {
    if (arr[i + 1] < arr[i]) {
      return false;
    }
  }

  return true;
}

void testSort(const std::string& sortName, void (*sort)(int[], int), int arr[],
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

void printArray(int arr[], int n) {
  for (int i = 0; i < n; ++i) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;

  return;
}

}  // namespace Util
