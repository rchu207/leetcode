// 119. Pascal's Triangle II

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row = {1};
        for (int r = 1; r <= rowIndex; r++) {
            row.push_back(1);
            for (int i = r - 1; i > 0; i--) {
                row[i] = row[i - 1] + row[i];
            }
        }
        return row;
    }
};
