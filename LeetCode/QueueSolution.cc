/*
 * QueueSolution.cc
 *
 *  Author: Erwin
 */

#include <LeetCode/QueueSolution.h>

#include <cassert>
#include <queue>

int QueueSolution::numSquares(int n) {
  assert(n > 0);

  std::queue<std::pair<int, int>> q;
  q.push(std::make_pair(n, 0));
  while (!q.empty()) {
    int num = q.front().first;
    int step = q.front().second;
    q.pop();

    std::vector<bool> visited(n + 1, false);
    visited[n] = true;

    for (int i = 1;; ++i) {
      int a = num - i * i;

      if (a < 0) {
        break;
      }

      if (a == 0) {
        return step + 1;
      }

      if (!visited[a]) {
        q.push(std::make_pair(a, step + 1));
        visited[a] = true;
      }
    }
  }
}
