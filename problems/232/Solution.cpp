// 232. Implement Queue using Stacks

class MyQueue {
public:
    MyQueue() {
    }

    void push(int x) {
        data1.push(x);
    }

    int pop() {
        auto value = peek();
        data2.pop();
        return value;
    }

    int peek() {
        if (data2.empty()) {
            while (!data1.empty()) {
                data2.push(data1.top());
                data1.pop();
            }
        }
        return data2.top();
    }

    bool empty() {
        return data1.empty() && data2.empty();
    }

private:
    stack<int> data1;
    stack<int> data2;
};
