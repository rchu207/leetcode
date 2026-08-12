// 394. Decode String

class Solution {
public:
    string decodeString(string s) {
        int n = s.length();
        stack<string> data;
        string digit;
        for (int i = 0; i < n; i++) {
            if (s[i] == ']') {
                processStack(data);
            } else if (s[i] >= '0' && s[i] <= '9') {
                digit += s[i];
            } else if (s[i] == '[') {
                data.push(digit);
                data.push(string(1, s[i]));
                digit = "";
            } else {
                data.push(string(1, s[i]));
            }
        }
        
        stack<string> data2;
        while (!data.empty()) {
            data2.push(data.top());
            data.pop();
        }
        string result;
        while (!data2.empty()) {
            result += data2.top();
            data2.pop();
        }
        return result;
    }

private:
    void processStack(stack<string>& data) {
        string combined;
        int n = 1;
        while (!data.empty()) {
            auto s = data.top();
            data.pop();
            if (s == "[") {
                n = std::stoi(data.top());
                data.pop();
                break;
            } else {
                combined = s + combined;
            }
        }
        string result;
        for (int i = 0; i < n; i++) {
            result += combined;
        }
        data.push(result);
    }
};
