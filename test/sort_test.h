/*
 * test.h
 *
 *  Created on: Jan 28, 2021
 *      Author: Erwin
 */

#ifndef TEST_SORT_TEST_H_
#define TEST_SORT_TEST_H_

namespace sort_test {

// Compare Selection Sort, Insertion Sort and Merge Sort with random arrays.
void Test1();
// Compare Selection Sort, Insertion Sort and Merge Sort with nearly ordered
// arrays.
void Test2();
// Compare Insertion Sort and Merge Sort 2 with nearly ordered arrays.
void Test3();
// Compare Merge Sort 2 and Quick Sort with random arrays.
void Test4();
// Compare Insertion sort, Merge Sort 2 and Quick Sort with nearly ordered
// arrays.
void Test5();

}  // namespace sort_test

#endif  // TEST_SORT_TEST_H_
