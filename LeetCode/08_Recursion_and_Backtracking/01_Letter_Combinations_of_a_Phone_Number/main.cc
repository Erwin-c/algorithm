/*
 * 17. Letter Combinations of a Phone Number.
 *
 *  时间复杂度: O(2 ^ len(s)).
 *  空间复杂度: O(len(s)).
 *
 *  Author: Erwin
 */

#include <iostream>
#include <string>
#include <vector>

class Solution {
 public:
  std::vector<std::string> letterCombinations(std::string digits) {
    if (digits.empty()) {
      return res;
    }

    findCombination(digits, 0, "");

    return res;
  }

 private:
  const std::string letterMap[10] = {
      " ",     // 0.
      "",      // 1.
      "abc",   // 2.
      "def",   // 3.
      "ghi",   // 4.
      "jkl",   // 5.
      "mno",   // 6.
      "pqrs",  // 7.
      "tuv",   // 8.
      "wxyz"   // 9.
  };

  std::vector<std::string> res;

  // s 中保存了此时从 digits[0, index - 1] 翻译得到的一个字母字符串.
  // 寻找和 digits[index] 匹配的字母, 获得 digits[0, index] 翻译得到的解.
  void findCombination(const std::string& digits, int index,
                       const std::string& s) {
    if (index == (int)digits.size()) {
      res.emplace_back(s);
      return;
    }

    char c = digits[index];
    std::string letters = letterMap[c - '0'];
    for (int i = 0; i < (int)letters.size(); ++i) {
      findCombination(digits, index + 1, s + letters[i]);
    }

    return;
  }
};

int main() {
  std::vector<std::string> res = Solution().letterCombinations("234");

  for (const auto& s : res) {
    std::cout << s << std::endl;
  }

  return 0;
}
