/*
 * MaxHeap.h
 *
 *  Author: Erwin
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
    data = new Item[capacity + 1];
    count = 0;
    this->capacity = capacity;
  }

  MaxHeap(Item arr[], int n) {
    data = new Item[n + 1];
    capacity = n;

    for (int i = 0; i < n; ++i) {
      data[i + 1] = arr[i];
    }
    count = n;

    // Heapify: Create a heap -> O(n)
    for (int i = count / 2; i >= 1; --i) {
      shiftDown(i);
    }
  }

  ~MaxHeap() { delete[] data; }

  int size() { return count; }

  bool isEmpty() { return count == 0; }

  // Create a heap -> O(nlogn)
  void insert(Item item) {
    assert(count + 1 <= capacity);

    data[count + 1] = item;
    ++count;

    shiftUp(count);

    return;
  }

  Item extractMax() {
    assert(count > 0);

    Item ret = data[1];

    std::swap(data[1], data[count]);
    --count;
    shiftDown(1);

    return ret;
  }

  Item getMax() {
    assert(count > 0);
    return data[1];
  }

  void testPrint() {
    // The size is limited to 100
    if (size() >= 100) {
      std::cout << "This print function can only work for less than 100 int!";
      return;
    }

    if (typeid(Item) != typeid(int)) {
      std::cout << "This print function can only work for int item!";
      return;
    }

    std::cout << "The max heap size is: " << size() << std::endl;
    std::cout << "Data in the max heap: ";
    for (int i = 1; i <= size(); i++) {
      // The data is limited within [0, 100)
      assert(data[i] >= 0 && data[i] < 100);
      std::cout << data[i] << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;

    int n = size();
    int maxLevel = 0;
    int numberPerLevel = 1;
    while (n > 0) {
      maxLevel += 1;
      n -= numberPerLevel;
      numberPerLevel *= 2;
    }

    int maxLevelNumber = int(pow(2, maxLevel - 1));
    int curTreeMaxLevelNumber = maxLevelNumber;
    int index = 1;
    for (int level = 0; level < maxLevel; ++level) {
      std::string line1 = std::string(maxLevelNumber * 3 - 1, ' ');

      int cur_level_number =
          std::min(count - int(pow(2, level)) + 1, int(pow(2, level)));
      bool isLeft = true;
      for (int indexCurLevel = 0; indexCurLevel < cur_level_number;
           ++index, ++indexCurLevel) {
        putNumberInLine(data[index], line1, indexCurLevel,
                        curTreeMaxLevelNumber * 3 - 1, isLeft);
        isLeft = !isLeft;
      }
      std::cout << line1 << std::endl;

      if (level == maxLevel - 1) {
        break;
      }

      std::string line2 = std::string(maxLevelNumber * 3 - 1, ' ');
      for (int indexCurLevel = 0; indexCurLevel < cur_level_number;
           ++indexCurLevel) {
        putBranchInLine(line2, indexCurLevel, curTreeMaxLevelNumber * 3 - 1);
      }

      std::cout << line2 << std::endl;

      curTreeMaxLevelNumber /= 2;
    }

    return;
  }

 private:
  void shiftUp(int k) {
    while (k > 1 && data[k / 2] < data[k]) {
      std::swap(data[k / 2], data[k]);
      k /= 2;
    }

    return;
  }

  void shiftDown(int k) {
    while (2 * k <= count) {
      int j = 2 * k;
      if (j + 1 <= count && data[j + 1] > data[j]) {
        ++j;
      }

      if (data[k] >= data[j]) {
        break;
      }

      std::swap(data[k], data[j]);
      k = j;
    }

    return;
  }

  void putNumberInLine(int num, std::string &line, int indexCurLevel,
                       int curTreeWidth, bool isLeft) {
    int subTreeWidth = (curTreeWidth - 1) / 2;
    int offset = indexCurLevel * (curTreeWidth + 1) + subTreeWidth;
    assert(offset + 1 < line.size());

    if (num >= 10) {
      line[offset + 0] = '0' + num / 10;
      line[offset + 1] = '0' + num % 10;
    } else {
      if (isLeft) {
        line[offset + 0] = '0' + num;
      } else {
        line[offset + 1] = '0' + num;
      }
    }

    return;
  }

  void putBranchInLine(std::string &line, int indexCurLevel, int curTreeWidth) {
    int subTreeWidth = (curTreeWidth - 1) / 2;
    int subSubTreeWidth = (subTreeWidth - 1) / 2;
    int offsetLeft = indexCurLevel * (curTreeWidth + 1) + subSubTreeWidth;
    assert(offsetLeft + 1 < line.size());

    int offsetRight =
        indexCurLevel * (curTreeWidth + 1) + subTreeWidth + 1 + subSubTreeWidth;
    assert(offsetRight < line.size());

    line[offsetLeft + 1] = '/';
    line[offsetRight + 0] = '\\';

    return;
  }

  Item *data;
  int count;
  int capacity;
};

#endif  // MAX_HEAP_H_
