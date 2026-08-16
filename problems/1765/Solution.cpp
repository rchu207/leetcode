// 1765. Map of Highest Peak

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();
        vector<vector<int>> heights(m, vector<int>(n,  -1));
        queue<pair<int, int>> paths;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (isWater[i][j] == 1) {
                    heights[i][j] = 0;
                    paths.push(std::make_pair(i, j));
                }
            }
        }

        while (!paths.empty()) {
            auto [row, col] = paths.front();
            paths.pop();
            vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
            for (auto& dir : directions) {
                auto nr = row + dir.first;
                auto nc = col + dir.second;
                if (nr < 0 || nr >= m || nc < 0 || nc >= n || heights[nr][nc] != -1)
                    continue;
                heights[nr][nc] = heights[row][col] + 1;
                paths.push(std::make_pair(nr, nc));
            }
        }
        return heights;
    }
};
