// 200. Number of Islands

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int answer = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    answer++;
                    bfs(grid, i, j);
                }
            }
        }
        return answer;
    }

private:
    void bfs(vector<vector<char>>& grid, int row, int col) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        q.push(std::make_pair(row, col));
        while (!q.empty()) {
            int count = q.size();
            for (int i = 0; i < count; i++) {
                auto pos = q.front();
                q.pop();
                if (grid[pos.first][pos.second] == '0')
                    continue;
                grid[pos.first][pos.second] = '0';
                
                auto up = pos.first - 1;
                if (up >= 0) {
                    q.push(std::make_pair(up, pos.second));
                }
                auto down = pos.first + 1;
                if (down < m) {
                    q.push(std::make_pair(down, pos.second));
                }
                auto left = pos.second - 1;
                if (left >= 0) {
                    q.push(std::make_pair(pos.first, left));
                }                
                auto right = pos.second + 1;
                if (right < n) {
                    q.push(std::make_pair(pos.first, right));
                }
            }
        }
    }
};
