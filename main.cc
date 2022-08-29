/*
 * main.cc
 *
 *  Created on: Jan 10, 2021
 *      Author: Erwin
 */

#include <cassert>
#include <iostream>

#include "Search/Search.h"
#include "Util/Util.h"

int main() {
  // Begin test
  // sort_test::Test1();
  // sort_test::Test2();
  // sort_test::Test3();
  // sort_test::Test4();
  // sort_test::Test5();
  // sort_test::Test6();
  // sort_test::Test7();
  // sort_test::Test8();
  // sort_test::Test9();
  // sort_test::Test10();
  // sort_test::Test11();

  int n = 1000000;
  int* data = Util::generateOrderedArray(n);

  clock_t startTime = clock();
  for (int i = 0; i < n; ++i) {
    assert(i == binarySearch(data, n, i));
  }

  clock_t endTime = clock();

  std::cout << "Binary search test complete!" << std::endl;
  std::cout << "Time cost: " << double(endTime - startTime) / CLOCKS_PER_SEC
            << "s" << std::endl;

  return 0;
}
