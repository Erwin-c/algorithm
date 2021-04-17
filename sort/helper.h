/*
 * helper.h
 *
 *  Created on: Jan 10, 2021
 *      Author: Erwin
 */

#ifndef HELPER_H_
#define HELPER_H_

#include <string>

namespace helper {

// Generate a random array with n elements between [range_left, range_right].
int* GenerateRandomArray(int n, int range_left, int range_right);
// Generate a nearly ordered array with n elements.
int* GenerateNearlyOrderedArray(int n, int swap_time);

int* CopyArray(int arr[], int n);

bool IsSorted(int arr[], int n);

void TestSort(const std::string& sort_name, void (*sort)(int[], int), int arr[],
              int n);

void PrintArray(int arr[], int n);

}  // namespace helper

#endif  // HELPER_H_
