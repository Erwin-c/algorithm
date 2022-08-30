/*
 * SortTest.h
 *
 *  Created on: Jan 28, 2021
 *      Author: Erwin
 */

#ifndef SORT_TEST_H_
#define SORT_TEST_H_

namespace SortTest {

// Selection Sort, Insertion Sort and Merge Sort for random arrays.
void test1();

// Selection Sort, Insertion Sort and Merge Sort for nearly ordered arrays.
void test2();

// Insertion Sort, Merge Sort Advanced for nearly ordered arrays.
void test3();

// Merge Sort Advanced and Quick Sort for random arrays.
void test4();

// Insertion Sort, Merge Sort Advanced and Quick Sort for nearly ordered arrays.
void test5();

// Insertion Sort, Merge Sort Advanced and Quick Sort Advanced for nearly
// ordered arrays.
void test6();

// Merge Sort Advanced and Quick Sort Advanced for arrays with many duplicate
// elements.
void test7();

// Merge Sort Advanced and Quick Sort 2 Ways for arrays with many duplicate
// elements.
void test8();

// Merge Sort Advanced, Quick Sort 2 Ways and Quick Sort 3 Ways for arrays with
// many duplicate elements.
void test9();

// Merge Sort Advanced, Quick Sort 2 Ways, Quick Sort 3 Ways and Heap Sort 1 for
// arrays with many duplicate elements.
void test10();

// Merge Sort Advanced, Quick Sort 2 Ways, Quick Sort 3 Ways, Heap Sort 1 and
// Heap Sort 2for arrays with many duplicate elements.
// In general, Heap Sort is worse than others. So Heap Sort is often used to
// process dynamic data, not for system sort.
void test11();

}  // namespace SortTest

#endif  // SORT_TEST_H_
