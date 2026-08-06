// 155. Min Stack

class MinStack {
public:
    MinStack() {
    }

    void push(int value) {
        if (value < min) {
            min = value;
        }
        data.push_back({value, min});
    }

    void pop() {
        data.pop_back();
        min = data.empty() ? 2147483647 : data.back()[1];
    }

    int top() {
        auto v = data.back();
        return v[0];
    }

    int getMin() {
        return min;
    }

private:
    vector<vector<int>> data;
    int min = 2147483647;
};
