/*
 * Util.cc
 *
 *  Author: Erwin
 */

#include "Util/Util.h"

#include <cassert>
#include <iostream>

namespace Util {

// Generate a random array with n elements between [rangeLeft, rangeRight].
int* generateRandomArray(int n, int rangeLeft, int rangeRight) {
  assert(rangeRight >= rangeLeft);

  int* arr = new int[n];
  srand(time(nullptr));
  for (int i = 0; i < n; ++i) {
    arr[i] = rand() % (rangeRight - rangeLeft + 1) + rangeLeft;
  }

  return arr;
}

// Generate an ordered array with n elements.
int* generateOrderedArray(int n) {
  int* arr = new int[n];
  for (int i = 0; i < n; ++i) {
    arr[i] = i;
  }

  return arr;
}

// Generate a nearly ordered array with n elements.
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

void printArray(int arr[], int n) {
  for (int i = 0; i < n; ++i) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;

  return;
}

}  // namespace Util
