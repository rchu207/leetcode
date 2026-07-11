// 498. Diagonal Traverse

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> answer;
        for (int d = 0; d < m + n - 1; d++) {
            if (d % 2 == 0) {
                int i = std::min(d, m - 1);
                while (i >= 0) {
                    int j = d - i;
                    if (j >= n)
                        break;
                    answer.push_back(mat[i][j]);
                    i--;
                }
            } else {
                int j = std::min(d, n - 1);
                while (j >= 0) {
                    int i = d - j;
                    if (i >= m)
                        break;
                    answer.push_back(mat[i][j]);
                    j--;
                }
            }
        }
        return answer;
    }
};
