// 4071. Minimum Rotations to Dial a Number II

class Solution {
public:
    int minRotations(int n, string s) {
        int total = 0;
        int prev = 0;
        for (char c : s) {
            total += dist(prev, c - '0');
            prev = c - '0';
        }

        int result = total;
        int last = s[n - 1] - '0';
        prev = 0;
        for (int k = 0; k < n; k++) {
            int cur = s[k] - '0';
            result = min(result, total - dist(prev, cur) + dist(prev, last));
            prev = cur;
        }
        return result;
    }

    int dist(int a, int b) {
        int d = std::abs(a - b);
        return std::min(d, 10 - d);
    }
};
