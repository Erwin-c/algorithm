/*
 * RecursionSolution.cc
 *
 *  Author: Erwin
 */

#include "LeetCode/RecursionSolution.h"

#include <cassert>

std::vector<std::string> RecursionSolution::letterCombinations(
    std::string digits) {
  res.clear();

  if (digits == "") {
    return res;
  }

  findCombination(digits, 0, "");

  return res;
}

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

std::vector<std::vector<std::string>> RecursionSolution::solveNQueens(int n) {
  res3.clear();

  col = std::vector<bool>(n, false);
  dia1 = std::vector<bool>(2 * n - 1, false);
  dia2 = std::vector<bool>(2 * n - 1, false);

  std::vector<int> row;
  putQueen(n, 0, row);

  return res3;
}

// s 中保存了此时从 digits[0, index - 1] 翻译得到的一个字母字符串.
// 寻找和 digits[index] 匹配的字母, 获得 digits[0, index] 翻译得到的解.
void RecursionSolution::findCombination(const std::string& digits, int index,
                                        const std::string& s) {
  if (index == (int)digits.size()) {
    res.emplace_back(s);
    return;
  }

  char c = digits[index];
  assert(c >= '0' && c <= '9' && c != '1');

  std::string letters = letterMap[c - '0'];
  for (int i = 0; i < (int)letters.size(); ++i) {
    findCombination(digits, index + 1, s + letters[i]);
  }

  return;
}

// p 中保存了一个有 index - 1 个元素的排列.
// 向这个排列的末尾添加第 index 个元素, 获得一个有 index 个元素的排列.
void RecursionSolution::generatePermutaion(const std::vector<int>& nums,
                                           int index, std::vector<int>& p) {
  if (index == (int)nums.size()) {
    res2.emplace_back(p);
    return;
  }

  for (int i = 0; i < (int)nums.size(); ++i) {
    if (!used[i]) {
      p.emplace_back(nums[i]);
      used[i] = true;
      generatePermutaion(nums, index + 1, p);
      p.pop_back();
      used[i] = false;
    }
  }

  return;
}

// 求解 C(n, k), 当前已经找到的组合存储在 c 中, 需要从 start 开始搜索新的元素.
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

// 求解 C(n, k), 当前已经找到的组合存储在 c 中, 需要从 start 开始搜索新的元素.
void RecursionSolution::generateCombinationsOptimized(int n, int k, int start,
                                                      std::vector<int>& c) {
  if (k == (int)c.size()) {
    res2.push_back(c);
    return;
  }

  // 还有 k - c.size() 个空位, 所以, [i ... n] 中至少要有 k - c.size() 个元素,
  // i 最多为 n - (k - c.size()) + 1.
  for (int i = start; i <= n - (k - (int)c.size()) + 1; ++i) {
    c.push_back(i);
    generateCombinations(n, k, i + 1, c);
    c.pop_back();
  }

  return;
}

// 从 board[startx][starty] 开始, 寻找 word[index ... word.size()).
bool RecursionSolution::searchWord(const std::vector<std::vector<char>>& board,
                                   const std::string& word, int index,
                                   int startx, int starty) {
  if (index == (int)word.size() - 1) {
    return board[startx][starty] == word[index];
  }

  if (board[startx][starty] == word[index]) {
    visited[startx][starty] = true;

    for (int i = 0; i < 4; ++i) {
      // 从 startx, starty 出发, 向四个方向寻找.
      int newx = startx + d[i][0];
      int newy = starty + d[i][1];

      if (inArea(newx, newy) && !visited[newx][newy] &&
          searchWord(board, word, index + 1, newx, newy)) {
        return true;
      }
    }

    visited[startx][starty] = false;
  }

  return false;
}

// 从 grid[x][y] 的位置开始, 进行 Floodfill.
// 保证 (x, y) 合法, 且 grid[x][y] 是没有被访问过的陆地.
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

// 尝试在一个 n 皇后问题中, 摆放第 index 行的皇后位置.
void RecursionSolution::putQueen(int n, int index, std::vector<int>& row) {
  if (index == n) {
    res3.push_back(generateBoard(n, row));
    return;
  }

  for (int i = 0; i < n; ++i) {
    // 尝试将第 index 行的皇后摆放在第 i 列.
    if (!col[i] && !dia1[index + i] && !dia2[index - i + n - 1]) {
      row.push_back(i);
      col[i] = true;
      dia1[index + i] = true;
      dia2[index - i + n - 1] = true;
      putQueen(n, index + 1, row);
      col[i] = false;
      dia1[index + i] = false;
      dia2[index - i + n - 1] = false;
      row.pop_back();
    }
  }

  return;
}

std::vector<std::string> RecursionSolution::generateBoard(
    int n, std::vector<int>& row) {
  assert((int)row.size() == n);

  std::vector<std::string> board(n, std::string(n, '.'));
  for (int i = 0; i < n; ++i) {
    board[i][row[i]] = 'Q';
  }

  return board;
}
