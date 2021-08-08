/**
 * 使用数组实现循环队列.
 *
 * 使用双指针维护队列的头部和尾部元素, 注意两个指针初始值, 以及跨越数组边界的情
 * 况.
 *
 */

class MyCircularQueue {
  public:
    MyCircularQueue(int k)
        : size(0), max_size(k), pData(nullptr), head(0), tail(0) {
        pData = new int[k];
    }

    ~MyCircularQueue() {
        if (pData != nullptr)
            delete[] pData;
    }

    bool enQueue(int value) {
        if (size >= max_size)
            return false;
        *(pData + tail) = value;
        ++size;
        tail = (tail + 1) % max_size;
        return true;
    }

    bool deQueue() {
        if (size <= 0)
            return false;
        head = (head + 1) % max_size;
        --size;
        return true;
    }

    int Front() {
        if (size == 0)
            return -1;
        return *(pData + head);
    }

    int Rear() {
        if (size == 0)
            return -1;
        return *(pData + (tail > 0 ? tail - 1 : max_size - 1));
    }

    bool isEmpty() { return size == 0; }

    bool isFull() { return size == max_size; }

  private:
    int *pData;
    int size;
    int max_size;
    int head;
    int tail;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
