/*
 * LinkedListSolution.h
 *
 *  Author: Erwin
 */

#ifndef LINKED_LIST_SOLUTION_H_
#define LINKED_LIST_SOLUTION_H_

#include "ListNode/ListNode.h"

class LinkedListSolution {
 public:
  // 206.
  ListNode* reverseList(ListNode* head);

  // 203.
  ListNode* removeElements(ListNode* head, int val);

  // 24.
  ListNode* swapPairs(ListNode* head);

  // TBD: 24 optimized, not need 'next'.

  // 237.
  void deleteNode(ListNode* node);

  // 19.
  ListNode* removeNthFromEnd(ListNode* head, int n);
};

#endif  // LINKED_LIST_SOLUTION_H_
