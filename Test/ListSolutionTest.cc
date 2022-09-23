/*
 * ListSolutionTest.cc
 *
 *  Author: Erwin
 */

#include "LeetCode/ListSolution.h"
#include "gtest/gtest.h"

namespace {

TEST(ListSolutionTest, reverseList) {
  int arr[] = {1, 2, 3, 4, 5};
  int resArr[] = {5, 4, 3, 2, 1};

  ListNode* head = createLinkedList(arr, sizeof(arr) / sizeof(int));
  ListNode* resList = createLinkedList(resArr, sizeof(resArr) / sizeof(int));

  head = ListSolution().reverseList(head);

  EXPECT_TRUE(isLinkedListEqual(head, resList));

  deleteLinkedList(head);
  deleteLinkedList(resList);
}

TEST(ListSolutionTest, removeElements) {
  int arr[] = {1, 2, 6, 3, 4, 5, 6};
  int val = 6;
  int resArr[] = {1, 2, 3, 4, 5};

  ListNode* head = createLinkedList(arr, sizeof(arr) / sizeof(int));
  ListNode* resList = createLinkedList(resArr, sizeof(resArr) / sizeof(int));

  head = ListSolution().removeElements(head, val);

  EXPECT_TRUE(isLinkedListEqual(head, resList));

  deleteLinkedList(head);
  deleteLinkedList(resList);
}

}  // namespace
