// 622. Design Circular Queue

class MyCircularQueue {
public:
    MyCircularQueue(int k) : queue(k), head(0), count(0) {}

    bool enQueue(int value) {
        if (isFull())
            return false;
        queue[(head + count) % queue.size()] = value;
        count++;
        return true;
    }

    bool deQueue() {
        if (isEmpty())
            return false;
        head = (head + 1) % queue.size();
        count--;
        return true;
    }

    int Front() {
        return isEmpty() ? -1 : queue[head];
    }

    int Rear() {
        return isEmpty() ? -1 : queue[(head + count - 1) % queue.size()];
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == queue.size();
    }

private:
    vector<int> queue;
    int head;
    int count;
};
