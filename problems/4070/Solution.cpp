// 4070. Minimum Rotations to Dial a Number I

class Solution {
public:
    int minRotations(string s) {
        int rotations = 0;
        int start = 0;
        for (auto& c : s) {
            int digit = (c - '0');
            int d = std::abs(digit - start);
            rotations += std::min(d, 10 - d);
            start = digit;
        }
        return rotations;
    }
};
