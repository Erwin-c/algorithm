#include <iostream>

using namespace std;

#define InitSize 10  // 动态数组的初始尺寸.
#define IncSize 5  // 当动态数组存满数据后每次扩容所能多保存的数据元素数量.

template <typename T>  // T 代表数组中元素的类型.
class SeqList {
 public:
  SeqList(int length = InitSize);  // 构造函数, 参数可以有默认值.
  ~SeqList();                      // 析构函数.

  bool ListInsert(int i, const T& e);  // 在第 i 个位置插入指定元素 e.
  bool ListDelete(int i);              // 删除第 i 个位置的元素.
  bool GetElem(int i, T& e);           // 获得第 i 个位置的元素值.
  int LocateElem(const T& e);  // 按元素值查找其在顺序表中第一次出现的位置.

  void DispList();     // 输出顺序表中的所有元素.
  int ListLength();    // 获取顺序表的长度.
  void ReverseList();  // 翻转顺序表.

 private:
  void IncreaseSize();  // 当顺序表存满数据后可以调用此函数为顺序表扩容.

  T* m_data;      // 存放顺序表中的元素.
  int m_length;   // 顺序表当前长度 (当前有几个元素).
  int m_maxsize;  // 动态数组最大容量.
};

// 通过构造函数对顺序表进行初始化.
template <typename T>
SeqList<T>::SeqList(int length) {
  m_data = new T[length];  // 为一维数组动态分配内存.
  m_length = 0;  // 顺序表当前实际长度为 0, 表示还未向其中存入任何数据元素.
  m_maxsize = length;  // 顺序表最多可以存储 m_maxsize 个数据元素.
}

// 通过析构函数对顺序表进行资源释放.
template <typename T>
SeqList<T>::~SeqList() {
  delete[] m_data;
  // 非必须.
  // m_length = 0;
  // m_maxsize = 0;
}

// 在第 i 个位置 (位置编号从 1 开始) 插入指定元素 e.
// 时间复杂度: O(n), 时间开销主要源于元素的移动.
template <typename T>
bool SeqList<T>::ListInsert(int i, const T& e) {
  // 如果顺序表已经存满了数据, 则不允许再插入新数据了.
  if (m_length >= m_maxsize) {
    std::cout << "顺序表已满, 不能再进行插入操作了!" << std::endl;
    return false;
  }

  // 判断插入位置 i 是否合法, i 的合法值应该是 1 到 m_length + 1 之间.
  if (i < 1 || i > m_length + 1) {
    std::cout << "元素 " << e << " 插入的位置 " << i
              << " 不合法, 合法的位置是 1 到 " << m_length + 1 << " 之间!"
              << std::endl;
    return false;
  }

  // 从最后一个元素开始向前遍历到要插入新元素的第 i 个位置,
  // 分别将这些位置中原有的元素向后移动一个位置.
  for (int j = m_length; j >= i; --j) {
    m_data[j] = m_data[j - 1];
  }

  // 在指定位置 i 处插入元素 e, 因为数组下标从 0 开始, 所以这里用 i - 1
  // 表示插入位置所对应的数组下标.
  m_data[i - 1] = e;
  std::cout << "成功在位置为 " << i << " 处插入元素 " << m_data[i - 1] << "!"
            << std::endl;
  ++m_length;  // 实际表长 +1.

  return true;
}
