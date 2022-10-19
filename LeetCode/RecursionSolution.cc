/*
 * RecursionSolution.cc
 *
 *  Author: Erwin
 */

#include "LeetCode/RecursionSolution.h"

// Time: O(2 ^ n)
std::vector<std::string> RecursionSolution::letterCombinations(
    std::string digits) {
  res.clear();

  if (digits == "") {
    return res;
  }

  findCombinations(digits, 0, "");

  return res;
}

// Time: O(2 ^ n)
std::vector<std::vector<int>> RecursionSolution::permute(
    std::vector<int>& nums) {
  res2.clear();

  if (nums.size() == 0) {
    return res2;
  }

  used = std::vector<bool>(nums.size(), false);

  std::vector<int> p;
  generatePermutaion(nums, 0, p);

  return res2;
}

// Time: O(2 ^ n)
std::vector<std::vector<int>> RecursionSolution::combine(int n, int k) {
  res2.clear();

  if (n <= 0 || k <= 0 || n < k) {
    return res2;
  }

  std::vector<int> p;
  generateCombinations(n, k, 1, p);

  return res2;
}

std::vector<std::vector<int>> RecursionSolution::combineOptimized(int n,
                                                                  int k) {
  res2.clear();

  if (n <= 0 || k <= 0 || n < k) {
    return res2;
  }

  std::vector<int> p;
  generateCombinationsOptimized(n, k, 1, p);

  return res2;
}

bool RecursionSolution::exist(std::vector<std::vector<char>>& board,
                              std::string word) {
  m = (int)board.size();
  assert(m > 0);
  n = (int)board[0].size();

  visited = std::vector<std::vector<bool>>(m, std::vector<bool>(n, false));

  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      if (searchWord(board, word, 0, i, j)) {
        return true;
      }
    }
  }

  return false;
}

int RecursionSolution::numIsIslands(std::vector<std::vector<char>>& grid) {
  m = (int)grid.size();
  if (m == 0) {
    return 0;
  }

  n = (int)grid[0].size();

  visited = std::vector<std::vector<bool>>(m, std::vector<bool>(n, false));

  int res = 0;
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      if (grid[i][j] == '1' && !visited[i][j]) {
        ++res;
        dfs(grid, i, j);
      }
    }
  }

  return res;
}

void RecursionSolution::findCombinations(const std::string& digits,
                                         size_t index, const std::string& s) {
  if (index == digits.size()) {
    res.push_back(s);
    return;
  }

  char c = digits[index];
  assert(c >= '0' && c <= '9' && c != '1');

  std::string letters = letterMap[c - '0'];
  for (size_t i = 0; i < letters.size(); ++i) {
    findCombinations(digits, index + 1, s + letters[i]);
  }

  return;
}

void RecursionSolution::generatePermutaion(const std::vector<int>& nums,
                                           size_t index, std::vector<int>& p) {
  if (index == nums.size()) {
    res2.push_back(p);
    return;
  }

  for (size_t i = 0; i < nums.size(); ++i) {
    if (!used[i]) {
      p.push_back(nums[i]);
      used[i] = true;
      generatePermutaion(nums, index + 1, p);
      p.pop_back();
      used[i] = false;
    }
  }

  return;
}

void RecursionSolution::generateCombinations(int n, int k, int start,
                                             std::vector<int>& c) {
  if (k == (int)c.size()) {
    res2.push_back(c);
    return;
  }

  for (int i = start; i <= n; ++i) {
    c.push_back(i);
    generateCombinations(n, k, i + 1, c);
    c.pop_back();
  }

  return;
}

void RecursionSolution::generateCombinationsOptimized(int n, int k, int start,
                                                      std::vector<int>& c) {
  if (k == (int)c.size()) {
    res2.push_back(c);
    return;
  }

  for (int i = start; i <= n - (k - (int)c.size()) + 1; ++i) {
    c.push_back(i);
    generateCombinations(n, k, i + 1, c);
    c.pop_back();
  }

  return;
}

bool RecursionSolution::searchWord(const std::vector<std::vector<char>>& board,
                                   const std::string& word, int index,
                                   int startx, int starty) {
  if (index == (int)word.size() - 1) {
    return board[startx][starty] == word[index];
  }

  if (board[startx][starty] == word[index]) {
    for (int i = 0; i < 4; ++i) {
      visited[startx][starty] = true;

      int newx = startx + d[i][0];
      int newy = starty + d[i][1];

      if (inArea(newx, newy) && !visited[newx][newy] &&
          searchWord(board, word, index + 1, newx, newy)) {
        return true;
      }

      visited[startx][starty] = false;
    }
  }

  return false;
}

void RecursionSolution::dfs(std::vector<std::vector<char>>& grid, int x,
                            int y) {
  visited[x][y] = true;

  for (int i = 0; i < 4; ++i) {
    int newx = x + d2[i][0];
    int newy = y + d2[i][1];
    if (inArea(newx, newy) && !visited[newx][newy] && grid[newx][newy] == '1') {
      dfs(grid, newx, newy);
    }
  }

  return;
}

bool RecursionSolution::inArea(int x, int y) {
  return x >= 0 && x < m && y >= 0 && y < n;
}
