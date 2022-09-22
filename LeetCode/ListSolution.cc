/*
 * ListSolution.cc
 *
 *  Author: Erwin
 */

#include "LeetCode/ListSolution.h"

// Time: O(n)
// Space: O(n)
ListNode* ListSolution::reverseList(ListNode* head) {
  ListNode* pre = nullptr;
  ListNode* cur = head;
  while (cur != nullptr) {
    ListNode* next = cur->next;

    cur->next = pre;
    pre = cur;
    cur = next;
  }

  return pre;
}
