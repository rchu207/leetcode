// 739. Daily Temperatures
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> indexes;
        vector<int> answer(n, 0);
        
        indexes.push(0);
        for (int i = 1; i < n; i++) {
            while (!indexes.empty()) {
                auto index = indexes.top();
                if (temperatures[i] <= temperatures[index]) {
                    break;
                }
                answer[index] = i - index;
                indexes.pop();
            }
            indexes.push(i);
        }

        return answer;
    }
};
