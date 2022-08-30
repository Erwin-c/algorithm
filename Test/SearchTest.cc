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
  int n = 1000000;

  clock_t startTime = clock();
  for (int i = 0; i < n; ++i) {
    assert(i == binarySearch(Util::generateOrderedArray(n), n, i));
  }

  clock_t endTime = clock();

  std::cout << "Binary search test complete!" << std::endl;
  std::cout << "Time cost: " << double(endTime - startTime) / CLOCKS_PER_SEC
            << "s" << std::endl;

  return;
}

}  // namespace SearchTest
