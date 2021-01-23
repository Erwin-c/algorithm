/*
 * helper.cc
 *
 *  Created on: Jan 10, 2021
 *      Author: Erwin
 */

#include "helper.h"

#include <cassert>
#include <iostream>

namespace helper {

int* GenerateRandomArray(int n, int range_left, int range_right) {
  assert(range_right >= range_left);

  int* arr = new int[n];
  srand(time(nullptr));
  for (int i = 0; i < n; i++) {
    arr[i] = rand() % (range_right - range_left + 1) + range_left;
  }

  return arr;
}

int* GenerateNearlyOrderedArray(int n, int swap_time) {
  int* arr = new int[n];
  for (int i = 0; i < n; i++) {
    arr[i] = i;
  }

  srand(time(nullptr));
  for (int i = 0; i < swap_time; i++) {
    int posx = rand() % n;
    int posy = rand() % n;
    std::swap(arr[posx], arr[posy]);
  }

  return arr;
}

int* CopyArray(int arr[], int n) {
  int* des = new int[n];
  std::copy(arr, arr + n, des);
  return des;
}

bool IsSorted(int arr[], int n) {
  for (int i = 0; i < n - 1; i++) {
    if (arr[i + 1] < arr[i]) {
      return false;
    }
  }

  return true;
}

void TestSort(const std::string& sort_name, void (*sort)(int[], int), int arr[],
              int n) {
  clock_t start_time = clock();
  sort(arr, n);
  clock_t end_time = clock();

  assert(IsSorted(arr, n));

  std::cout << sort_name << ": "
            << (double)(end_time - start_time) / CLOCKS_PER_SEC << "s"
            << std::endl;
}

void PrintArray(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

}  // namespace helper
