// 279. Perfect Squares

class Solution {
public:
    int numSquares(int n) {
        int step = 0;
        queue<int> q;
        q.push(0);
        vector<int> visit(10000 + 1, 0);
        while (!q.empty()) {
            int count = q.size();
            for (int i = 0; i < count; i++) {
                auto value = q.front();
                q.pop();
                if (value == n) {
                    return step;
                }
                for (int j = 1; j <= n / 2; j++) {
                    auto next = value + j * j;
                    if (next <= n) {
                        if (visit[next] == 0)
                            q.push(next);
                        visit[next] = 1;
                    } else {
                        break;
                    }
                }
            }
            step++;
        }
        return step;
    }
};
