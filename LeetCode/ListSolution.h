/*
 * ListSolution.h
 *
 *  Author: Erwin
 */

#ifndef LIST_SOLUTION_H_
#define LIST_SOLUTION_H_

struct ListNode {
  int val;
  ListNode* next;
};

class ListSolution {
 public:
  // 206
  ListNode* reverseList(ListNode* head);
};

#endif  // LIST_SOLUTION_H_
