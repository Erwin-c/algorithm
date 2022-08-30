/*
 * main.cc
 *
 *  Created on: Jan 10, 2021
 *      Author: Erwin
 */

#include "Test/SearchTest.h"
#include "Test/SolutionTest.h"
#include "Test/SortTest.h"

int main() {
  // Begin test
  SortTest::test1();
  SortTest::test2();
  SortTest::test3();
  SortTest::test4();
  SortTest::test5();
  SortTest::test6();
  SortTest::test7();
  SortTest::test8();
  SortTest::test9();
  SortTest::test10();
  SortTest::test11();

  SearchTest::test1();

  SolutionTest::moveZerosTest();

  return 0;
}
