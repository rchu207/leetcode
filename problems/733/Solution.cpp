// 733. Flood Fill

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int fromColor = image[sr][sc];
        int toColor = color;
        stack<pair<int, int>> positions;
        positions.push(std::make_pair(sr, sc));
        while (!positions.empty()) {
            auto pos = positions.top();
            positions.pop();

            int row = pos.first;
            int col = pos.second;
            if (image[row][col] == fromColor && image[row][col] != toColor) {
                image[row][col] = toColor;
                if (row - 1 >= 0) {
                    positions.push(std::make_pair(row - 1, col));
                }
                if (col - 1 >= 0) {
                    positions.push(std::make_pair(row, col - 1));
                }
                if (row + 1 < image.size()) {
                    positions.push(std::make_pair(row + 1, col));
                }
                if (col + 1 < image[row].size()) {
                    positions.push(std::make_pair(row, col + 1));
                }
            }
        }
        return image;
    }
};
