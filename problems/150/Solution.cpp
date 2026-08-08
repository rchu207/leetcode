// 150. Evaluate Reverse Polish Notation

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> values;
        for (auto& token : tokens) {
            if (token == "+") {
                int v1 = values.top();
                values.pop();
                int v2 = values.top();
                values.pop();
                values.push(v1 + v2);
            } else if (token == "-") {
                int v1 = values.top();
                values.pop();
                int v2 = values.top();
                values.pop();
                values.push(v2 - v1);
            } else if (token == "*") {
                int v1 = values.top();
                values.pop();
                int v2 = values.top();
                values.pop();
                values.push(v1 * v2);
            } else if (token == "/") {
                int v1 = values.top();
                values.pop();
                int v2 = values.top();
                values.pop();
                values.push(v2 / v1);
            } else {
                values.push(std::stoi(token));
            }
        }
        return values.top();
    }
};
