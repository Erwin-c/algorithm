/*
 * Sort.h
 *
 *  Created on: Jan 10, 2021
 *      Author: Erwin
 */

#ifndef SORT_H_
#define SORT_H_

void selectionSort(int arr[], int n);

void insertionSort(int arr[], int n);

void mergeSort(int arr[], int n);

// Optimation mainly for nearly ordered arrays
void mergeSortAdvanced(int arr[], int n);

void quickSort(int arr[], int n);

void quickSortAdvanced(int arr[], int n);

void quickSort2Ways(int arr[], int n);

void quickSort3Ways(int arr[], int n);

// Creat a heap, Insert -> O(nlogn), related to 'level'
void heapSort1(int arr[], int n);

// Create a heap, Heapify -> O(n)
void heapSort2(int arr[], int n);

#endif  // SORT_H_
