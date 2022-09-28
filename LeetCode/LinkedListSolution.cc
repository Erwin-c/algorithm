/*
 * LinkedListSolution.cc
 *
 *  Author: Erwin
 */

#include "LeetCode/LinkedListSolution.h"

#include <cassert>

// Time: O(n)
// Space: O(1)
ListNode* LinkedListSolution::reverseList(ListNode* head) {
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
ListNode* LinkedListSolution::removeElements(ListNode* head, int val) {
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

// Time: O(n)
// Space: O(1)
ListNode* LinkedListSolution::swapPairs(ListNode* head) {
  ListNode* dummyHead = new ListNode(0);
  dummyHead->next = head;

  ListNode* p = dummyHead;
  while (p->next != nullptr && p->next->next != nullptr) {
    ListNode* node1 = p->next;
    ListNode* node2 = node1->next;
    ListNode* next = node2->next;

    node2->next = node1;
    node1->next = next;
    p->next = node2;

    p = node1;
  }

  ListNode* retNode = dummyHead->next;
  delete dummyHead;

  return retNode;
}

// Time: O(n)
// Space: O(1)
void LinkedListSolution::deleteNode(ListNode* node) {
  if (node == nullptr) {
    return;
  }

  if (node->next == nullptr) {
    delete node;
    node = nullptr;
    return;
  }

  node->val = node->next->val;
  ListNode* delNode = node->next;
  node->next = delNode->next;

  delete delNode;

  return;
}

// Time: O(n)
// Space: O(1)
ListNode* LinkedListSolution::removeNthFromEnd(ListNode* head, int n) {
  assert(n >= 0);

  ListNode* dummyHead = new ListNode(0);
  dummyHead->next = head;

  ListNode* p = dummyHead;
  ListNode* q = dummyHead;
  for (int i = 0; i < n + 1; ++i) {
    assert(q != nullptr);
    q = q->next;
  }

  while (q != nullptr) {
    p = p->next;
    q = q->next;
  }

  ListNode* delNode = p->next;
  p->next = delNode->next;
  delete delNode;

  ListNode* retNode = dummyHead->next;
  delete dummyHead;

  return retNode;
}
