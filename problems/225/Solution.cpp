// 225. Implement Stack using Queues

class MyStack {
public:
    MyStack() {
    }
    
    void push(int x) {
        q.push(x);
        last = x;
    }
    
    int pop() {
        queue<int> q2;
        int n = q.size();
        for (int i = 0; i < n - 1; i++) {
            last = q.front();
            q2.push(last);
            q.pop();
        }
        auto tmp = q.front();
        q = q2;
        return tmp;
    }
    
    int top() {
        return last;
    }
    
    bool empty() {
        return q.empty();
    }

private:
    queue<int> q;
    int last;
};
