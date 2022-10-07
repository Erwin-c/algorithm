/*
 * QueueSolution.cc
 *
 *  Author: Erwin
 */

#include <LeetCode/QueueSolution.h>

#include <cassert>
#include <queue>
#include <unordered_map>

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

// Time: O(nlogk)
// Space: O(n)
std::vector<int> QueueSolution::topKFrequent(std::vector<int>& nums, int k) {
  assert(k > 0);

  std::unordered_map<int, int> freq;
  for (size_t i = 0; i < nums.size(); ++i) {
    ++freq[nums[i]];
  }

  assert(k <= freq.size());

  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                      std::greater<std::pair<int, int>>>
      pq;

  for (std::unordered_map<int, int>::iterator iter = freq.begin();
       iter != freq.end(); ++iter) {
    if ((int)pq.size() == k) {
      if (iter->second > pq.top().first) {
        pq.pop();
        pq.push(std::make_pair(iter->second, iter->first));
      }
    } else {
      pq.push(std::make_pair(iter->second, iter->first));
    }
  }

  std::vector<int> res;
  while (!pq.empty()) {
    res.push_back(pq.top().second);
    pq.pop();
  }

  return res;
}
