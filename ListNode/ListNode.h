/*
 * ListNode.h
 *
 *  Author: Erwin
 */

#ifndef LIST_NODE_H_
#define LIST_NODE_H_

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* createLinkedList(int arr[], int n);

void deleteLinkedList(ListNode* head);

bool isLinkedListEqual(ListNode* head1, ListNode* head2);

void printLinkedList(ListNode* head);

#endif  // LIST_NODE_H_
