/*
 * sort.h
 *
 *  Created on: Jan 10, 2021
 *      Author: Erwin
 */

#ifndef SORT_H_
#define SORT_H_

namespace sort {

void SelectionSort(int arr[], int n);

void InsertionSort(int arr[], int n);

void MergeSort(int arr[], int n);

// Optimation mainly for nearly ordered arrays.
void MergeSortAdvanced(int arr[], int n);

void QuickSort(int arr[], int n);

void QuickSortAdvanced(int arr[], int n);

void QuickSort2Ways(int arr[], int n);

void QuickSort3Ways(int arr[], int n);

// Creat a heap, Insert -> O(nlogn), related to 'level'.
void HeapSort1(int arr[], int n);

// Create a heap, Heapify -> O(n).
void HeapSort2(int arr[], int n);

}  // namespace sort

#endif  // SORT_H_
