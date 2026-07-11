// 118. Pascal's Triangle

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> answer(numRows);
        for (int r = 0; r < numRows; r++) {
            answer[r].resize(r + 1, 1);
            for (int i = 1; i < r; i++) {
                answer[r][i] = answer[r - 1][i - 1] + answer[r - 1][i];
            }
        }
        return answer;
    }
};

