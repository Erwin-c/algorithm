/*
 * QueueSolution.h
 *
 *  Author: Erwin
 */

#ifndef QUEUE_SOLUTION_H_
#define QUEUE_SOLUTION_H_

#include <vector>

class QueueSolution {
 public:
  // 279
  int numSquares(int n);

  // 347
  std::vector<int> topKFrequent(std::vector<int>& nums, int k);

  // TBD: 347, k --> n
};

#endif  // QUEUE_SOLUTION_H_
