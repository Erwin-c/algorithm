/*
 * helper.h
 *
 *  Created on: Jan 10, 2021
 *      Author: Erwin
 */

#ifndef SORT_HELPER_H_
#define SORT_HELPER_H_

#include <string>

namespace helper {

// Generate a random array with n elements between [rangeL, rangeR].
int* GenerateRandomArray(int n, int range_left, int range_right);

int* CopyArray(int arr[], int n);

void TestSort(const std::string& sort_name, void (*sort)(int[], int), int arr[],
              int n);

bool IsSorted(int arr[], int n);

void PrintArray(int arr[], int n);

}  // namespace helper

#endif  // SORT_HELPER_H_