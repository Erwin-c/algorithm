/*
 * max_heap.h
 *
 *  Created on: Dec 19, 2021
 *      Author: Erwin
 */

#ifndef MAX_HEAP_H_
#define MAX_HEAP_H_

#include <cassert>
#include <cmath>
#include <iostream>
#include <string>
#include <typeinfo>

template <typename Item>
class MaxHeap {
 public:
  MaxHeap(int capacity) {
    data_ = new Item[capacity + 1];
    count_ = 0;
    capacity_ = capacity;
  }

  MaxHeap(Item arr[], int n) {
    data_ = new Item[n + 1];
    capacity_ = n;

    for (int i = 0; i < n; ++i) {
      data_[i + 1] = arr[i];
    }
    count_ = n;

    // Heapify: Create a heap -> O(n).
    for (int i = count_ / 2; i >= 1; --i) {
      ShiftDown(i);
    }
  }

  ~MaxHeap() { delete[] data_; }

  int size() { return count_; }

  bool IsEmpty() { return count_ == 0; }

  // Create a heap -> O(nlogn).
  void Insert(Item item) {
    assert(count_ + 1 <= capacity);

    data_[count_ + 1] = item;
    ++count_;

    ShiftUp(count_);

    return;
  }

  Item ExtractMax() {
    assert(count > 0);

    Item ret = data_[1];

    std::swap(data_[1], data_[count_]);
    --count_;
    ShiftDown(1);

    return ret;
  }

  Item GetMax() {
    assert(count > 0);
    return data_[1];
  }

  void TestPrint() {
    // The size is limited to 100.
    if (size() >= 100) {
      std::cout << "This print function can only work for less than 100 int.";
      return;
    }

    if (typeid(Item) != typeid(int)) {
      std::cout << "This print function can only work for int item.";
      return;
    }

    std::cout << "The max heap size is: " << size() << std::endl;
    std::cout << "Data in the max heap: ";
    for (int i = 1; i <= size(); i++) {
      // The data is limited within [0, 100).
      assert(data_[i] >= 0 && data_[i] < 100);
      std::cout << data_[i] << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;

    int n = size();
    int max_level = 0;
    int number_per_level = 1;
    while (n > 0) {
      max_level += 1;
      n -= number_per_level;
      number_per_level *= 2;
    }

    int max_level_number = int(pow(2, max_level - 1));
    int cur_tree_max_level_number = max_level_number;
    int index = 1;
    for (int level = 0; level < max_level; ++level) {
      std::string line1 = std::string(max_level_number * 3 - 1, ' ');

      int cur_level_number =
          std::min(count_ - int(pow(2, level)) + 1, int(pow(2, level)));
      bool isLeft = true;
      for (int index_cur_level = 0; index_cur_level < cur_level_number;
           ++index, ++index_cur_level) {
        PutNumberInLine(data_[index], line1, index_cur_level,
                        cur_tree_max_level_number * 3 - 1, isLeft);
        isLeft = !isLeft;
      }
      std::cout << line1 << std::endl;

      if (level == max_level - 1) {
        break;
      }

      std::string line2 = std::string(max_level_number * 3 - 1, ' ');
      for (int index_cur_level = 0; index_cur_level < cur_level_number;
           ++index_cur_level) {
        PutBranchInLine(line2, index_cur_level,
                        cur_tree_max_level_number * 3 - 1);
      }

      std::cout << line2 << std::endl;

      cur_tree_max_level_number /= 2;
    }

    return;
  }

 private:
  void ShiftUp(int k) {
    while (k > 1 && data_[k / 2] < data_[k]) {
      std::swap(data_[k / 2], data_[k]);
      k /= 2;
    }

    return;
  }

  void ShiftDown(int k) {
    while (2 * k <= count_) {
      int j = 2 * k;
      if (j + 1 <= count_ && data_[j + 1] > data_[j]) {
        ++j;
      }

      if (data_[k] >= data_[j]) {
        break;
      }

      std::swap(data_[k], data_[j]);
      k = j;
    }

    return;
  }

  void PutNumberInLine(int num, std::string &line, int index_cur_level,
                       int cur_tree_width, bool is_left) {
    int sub_tree_width = (cur_tree_width - 1) / 2;
    int offset = index_cur_level * (cur_tree_width + 1) + sub_tree_width;
    assert(offset + 1 < line.size());
    if (num >= 10) {
      line[offset + 0] = '0' + num / 10;
      line[offset + 1] = '0' + num % 10;
    } else {
      if (is_left)
        line[offset + 0] = '0' + num;
      else
        line[offset + 1] = '0' + num;
    }

    return;
  }

  void PutBranchInLine(std::string &line, int index_cur_level,
                       int cur_tree_width) {
    int sub_tree_width = (cur_tree_width - 1) / 2;
    int sub_sub_tree_width = (sub_tree_width - 1) / 2;
    int offset_left =
        index_cur_level * (cur_tree_width + 1) + sub_sub_tree_width;
    assert(offset_left + 1 < line.size());
    int offset_right = index_cur_level * (cur_tree_width + 1) + sub_tree_width +
                       1 + sub_sub_tree_width;
    assert(offset_right < line.size());

    line[offset_left + 1] = '/';
    line[offset_right + 0] = '\\';

    return;
  }

  Item *data_;
  int count_;
  int capacity_;
};

#endif  // MAX_HEAP_H_
