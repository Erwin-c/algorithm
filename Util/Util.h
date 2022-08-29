/*
 * Util.h
 *
 *  Created on: Jan 10, 2021
 *      Author: Erwin
 */

#ifndef UTIL_H_
#define UTIL_H_

#include <string>

namespace Util {

// Generate a random array with n elements between [rangeLeft, rangeRight]
int* generateRandomArray(int n, int rangeLeft, int rangeRight);

// Generate an ordered array with n elements
int* generateOrderedArray(int n);

// Generate a nearly ordered array with n elements
int* generateNearlyOrderedArray(int n, int swapTime);

int* copyArray(int arr[], int n);

bool isSorted(int arr[], int n);

void testSort(const std::string& sortName, void (*sort)(int[], int), int arr[],
              int n);

void printArray(int arr[], int n);

}  // namespace Util

#endif  // UTIL_H_
