/*
 * RecursionSolution.h
 *
 *  Author: Erwin
 */

#ifndef RECURSION_SOLUTION_H_
#define RECURSION_SOLUTION_H_

#include <cassert>
#include <string>
#include <vector>

class RecursionSolution {
 public:
  // 17.
  std::vector<std::string> letterCombinations(std::string digits);

  // 46.
  std::vector<std::vector<int>> permute(std::vector<int>& nums);

  // 77.
  std::vector<std::vector<int>> combine(int n, int k);

  // 77 optimized.
  std::vector<std::vector<int>> combineOptimized(int n, int k);

  // 79. Word Search.
  // 时间复杂度: O(m * n * m * n)
  // 空间复杂度: O(m * n)
  bool exist(std::vector<std::vector<char>>& board, std::string word);

  // 200. Number of Islands (Floodfill).
  // 时间复杂度: O(n * m).
  // 空间复杂度: O(n * m).
  int numIsIslands(std::vector<std::vector<char>>& grid);

  // 51. N-Queens.
  // 时间复杂度: O(n ^ n).
  // 空间复杂度: O(n).
  std::vector<std::vector<std::string>> solveNQueens(int n);

 private:
  const std::string letterMap[10] = {
      " ",     // 10
      "",      // 1
      "abc",   // 2
      "def",   // 3
      "ghi",   // 4
      "jkl",   // 5
      "mno",   // 6
      "pqrs",  // 7
      "tuv",   // 8
      "wxyz"   // 9
  };

  int d[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};   // 79. Word Search.
  int d2[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};  // 200. Number of Islands.

  int m, n;  // 79. Word Search.
             // 200. Number of Islands.

  std::vector<std::string> res;

  std::vector<std::vector<int>> res2;

  std::vector<std::vector<std::string>> res3;  // 51. N-Queens.

  std::vector<bool> col, dia1, dia2;  // 51. N-Queens.

  std::vector<bool> used;

  std::vector<std::vector<bool>> visited;  // 79. Word Search.
                                           // 200. Number of Islands.

  void findCombinations(const std::string& digits, size_t index,
                        const std::string& s);

  void generatePermutaion(const std::vector<int>& nums, size_t index,
                          std::vector<int>& p);

  void generateCombinations(int n, int k, int start, std::vector<int>& c);

  void generateCombinationsOptimized(int n, int k, int start,
                                     std::vector<int>& c);

  // 从 board[startx][starty] 开始, 寻找 word[index ... word.size()).
  bool searchWord(const std::vector<std::vector<char>>& board,
                  const std::string& word, int index, int startx, int starty);

  // 从 grid[x][y] 的位置开始, 进行 Floodfill.
  // 保证 (x, y) 合法, 且 grid[x][y] 是没有被访问过的陆地.
  void dfs(std::vector<std::vector<char>>& grid, int x, int y);

  bool inArea(int x, int y);

  // 51. N-Queens.
  // 尝试在一个 n 皇后问题中, 摆放第 index 行的皇后位置.
  void putQueen(int n, int index, std::vector<int>& row);

  // 51. N-Queens.
  std::vector<std::string> generateBoard(int n, std::vector<int>& row);
};

#endif  // RECURSION_SOLUTION_H_
