/*
 * test.h
 *
 *  Created on: Jan 28, 2021
 *      Author: Erwin
 */

#ifndef SORT_TEST_H_
#define SORT_TEST_H_

namespace sort_test {

// Compare Selection Sort, Insertion Sort and Merge Sort with random arrays.
void Test1();
// Compare Selection Sort, Insertion Sort and Merge Sort with nearly ordered
// arrays.
void Test2();
// Compare Insertion Sort and Merge Sort Advanced with nearly ordered arrays.
void Test3();
// Compare Merge Sort Advanced and Quick Sort with random arrays.
void Test4();
// Compare Insertion Sort, Merge Sort Advanced and Quick Sort with nearly
// ordered arrays.
void Test5();
// Compare Insertion Sort, Merge Sort Advanced and Quick Sort Advanced with
// nearly ordered arrays.
void Test6();
// Compare Merge Sort Advanced and Quick Sort Advanced with arrays which have
// more duplicate elements.
void Test7();

}  // namespace sort_test

#endif  // SORT_TEST_H_
