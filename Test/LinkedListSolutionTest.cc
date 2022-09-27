/*
 * LinkedListSolutionTest.cc
 *
 *  Author: Erwin
 */

#include "LeetCode/LinkedListSolution.h"
#include "gtest/gtest.h"

namespace {

TEST(LinkedListSolutionTest, reverseList) {
  int arr[] = {1, 2, 3, 4, 5};
  int resArr[] = {5, 4, 3, 2, 1};

  ListNode* head = createLinkedList(arr, sizeof(arr) / sizeof(int));
  ListNode* resList = createLinkedList(resArr, sizeof(resArr) / sizeof(int));

  head = LinkedListSolution().reverseList(head);

  EXPECT_TRUE(isLinkedListEqual(head, resList));

  deleteLinkedList(head);
  deleteLinkedList(resList);
}

TEST(LinkedListSolutionTest, removeElements) {
  int arr[] = {1, 2, 6, 3, 4, 5, 6};
  int val = 6;
  int resArr[] = {1, 2, 3, 4, 5};

  ListNode* head = createLinkedList(arr, sizeof(arr) / sizeof(int));
  ListNode* resList = createLinkedList(resArr, sizeof(resArr) / sizeof(int));

  head = LinkedListSolution().removeElements(head, val);

  EXPECT_TRUE(isLinkedListEqual(head, resList));

  deleteLinkedList(head);
  deleteLinkedList(resList);
}

TEST(LinkedListSolutionTest, swapPairs) {
  int arr[] = {1, 2, 3, 4};
  int resArr[] = {2, 1, 4, 3};

  ListNode* head = createLinkedList(arr, sizeof(arr) / sizeof(int));
  ListNode* resList = createLinkedList(resArr, sizeof(resArr) / sizeof(int));

  head = LinkedListSolution().swapPairs(head);

  EXPECT_TRUE(isLinkedListEqual(head, resList));

  deleteLinkedList(head);
  deleteLinkedList(resList);
}

TEST(LinkedListSolutionTest, removeNthFromEnd) {
  int arr[] = {1, 2, 3, 4, 5};
  int n = 2;
  int resArr[] = {1, 2, 3, 5};

  ListNode* head = createLinkedList(arr, sizeof(arr) / sizeof(int));
  ListNode* resList = createLinkedList(resArr, sizeof(resArr) / sizeof(int));

  head = LinkedListSolution().removeNthFromEnd(head, n);

  EXPECT_TRUE(isLinkedListEqual(head, resList));

  deleteLinkedList(head);
  deleteLinkedList(resList);
}

}  // namespace
