/*
 * SearchTest.cc
 *
 *  Created on: Aug 30, 2022
 *      Author: Erwin
 */

#include "Test/SearchTest.h"

#include <cassert>
#include <iostream>

#include "Search/Search.h"
#include "Util/Util.h"

namespace SearchTest {

void test1() {
  std::cout << "-------------------------------------------------" << std::endl;
  int n = 1000000;
  int* arr = Util::generateOrderedArray<int>(n);

  clock_t startTime = clock();
  for (int i = 0; i < n; ++i) {
    assert(i == Search::binarySearch(arr, n, i));
  }

  clock_t endTime = clock();

  std::cout << "Binary search test complete!" << std::endl;
  std::cout << "Time cost: " << double(endTime - startTime) / CLOCKS_PER_SEC
            << "s" << std::endl;

  delete[] arr;

  std::cout << "End ^-^" << std::endl;

  return;
}

}  // namespace SearchTest
