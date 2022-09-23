/*
 * ListNode.cc
 *
 *  Author: Erwin
 */

#include "ListNode/ListNode.h"

#include <iostream>

ListNode* createLinkedList(int arr[], int n) {
  if (n == 0) {
    return nullptr;
  }

  ListNode* head = new ListNode(arr[0]);

  ListNode* curNode = head;
  for (int i = 1; i < n; ++i) {
    curNode->next = new ListNode(arr[i]);
    curNode = curNode->next;
  }

  return head;
}

void deleteLinkedList(ListNode* head) {
  ListNode* curNode = head;
  while (curNode != nullptr) {
    ListNode* delNode = curNode;
    curNode = curNode->next;
    delete delNode;
  }

  return;
}

bool isLinkedListEqual(ListNode* head1, ListNode* head2) {
  ListNode* p = head1;
  ListNode* q = head2;

  while (p != nullptr && q != nullptr && p->val == q->val) {
    p = p->next;
    q = q->next;
  }

  return p == q ? 1 : 0;
}

void printLinkedList(ListNode* head) {
  ListNode* curNode = head;
  while (curNode != nullptr) {
    std::cout << curNode->val << "->";
    curNode = curNode->next;
  }

  std::cout << "nullptr" << std::endl;

  return;
}
