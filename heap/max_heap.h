/*
 * max_heap.h
 *
 *  Created on: Dec 19, 2021
 *      Author: Erwin
 */

#ifndef MAX_HEAP_H_
#define MAX_HEAP_H_

template <typename Item>
class MaxHeap {
 public:
  MaxHeap(int capacity) {
    data_ = new Item[capacity + 1];
    count_ = 0;
  }

  ~MaxHeap() { delete[] data_; }

  int size() { return count_; }

  bool IsEmpty() { return count_ == 0; }

 private:
  Item *data_;
  int count_;
};

#endif  // MAX_HEAP_H_
