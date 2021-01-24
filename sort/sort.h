/*
 * sort.h
 *
 *  Created on: Jan 10, 2021
 *      Author: Erwin
 */

#ifndef SORT_SORT_H_
#define SORT_SORT_H_

#include <algorithm>

namespace sort {

void SelectionSort(int arr[], int n);

void InsertionSort(int arr[], int l, int r);
void InsertionSort(int arr[], int n);

void Merge(int arr[], int l, int mid, int r);
void MergeSort(int arr[], int l, int r);
void MergeSort(int arr[], int n);

int Partition(int arr[], int l, int r);
void QuickSort(int arr[], int l, int r);
void QuickSort(int arr[], int n);

}  // namespace sort

#endif  // SORT_SORT_H_
