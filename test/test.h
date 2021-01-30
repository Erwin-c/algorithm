/*
 * test.h
 *
 *  Created on: Jan 28, 2021
 *      Author: Erwin
 */

#ifndef TEST_TEST_H_
#define TEST_TEST_H_

namespace test {

// Compare Selection Sort, Insertion Sort and Merge Sort with random arrays.
void sort_test_1();
// Compare Selection Sort, Insertion Sort and Merge Sort with nearly ordered
// arrays.
void sort_test_2();
// Compare Insertion Sort and Merge Sort 2 with nearly ordered arrays.
void sort_test_3();
// Compare Merge Sort 2 and Quick Sort with random arrays.
void sort_test_4();
// Compare Insertion sort, Merge Sort 2 and Quick Sort with nearly ordered
// arrays.
void sort_test_5();

}  // namespace test

#endif  // TEST_TEST_H_
