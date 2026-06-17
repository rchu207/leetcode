// 36. Valid Sudoku

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Check row and column
        for (int i = 0; i < 9; i++) {
            int row[3+9] = {0};
            int col[3+9] = {0};
            for (int j = 0; j < 9; j++) {
                row[board[i][j]-'.']++;
                col[board[j][i]-'.']++;
            }
            for (int k = 3; k < 3 + 9; k++) {
                if (row[k] > 1 || col[k] > 1)
                    return false;
            }
        }
        // Check sub-boxes
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                int box[3+9] = {0};
                for (int m = 0; m < 3; m++) {
                    for (int n = 0; n < 3; n++) {
                        box[board[i*3+m][j*3+n]-'.']++;
                    }
                }
                for (int k = 3; k < 3 + 9; k++) {
                    if (box[k] > 1)
                        return false;
                }                
            }
        }
        return true;
    }
};
