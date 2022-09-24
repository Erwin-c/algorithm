/*
 * ListSolution.cc
 *
 *  Author: Erwin
 */

#include "LeetCode/ListSolution.h"

// Time: O(n)
// Space: O(1)
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

// Time: O(n)
// Space: O(1)
ListNode* ListSolution::removeElements(ListNode* head, int val) {
  ListNode* dummyHead = new ListNode(0);
  dummyHead->next = head;

  ListNode* cur = dummyHead;
  while (cur->next != nullptr) {
    if (cur->next->val == val) {
      ListNode* delNode = cur->next;
      cur->next = delNode->next;
      delete delNode;
    } else {
      cur = cur->next;
    }
  }

  ListNode* retNode = dummyHead->next;
  delete dummyHead;

  return retNode;
}
