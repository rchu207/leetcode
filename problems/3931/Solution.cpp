// 3931. Check Adjacent Digit Differences

class Solution {
public:
    bool isAdjacentDiffAtMostTwo(string s) {
        for (int i = 0; i < s.length() - 1; i++) {
            if (s[i] >= s[i + 1]) {
                if (s[i] - s[i + 1] > 2)
                    return false;
            } else {
                if (s[i + 1] - s[i] > 2)
                    return false;
            }
        }
        return true;
    }
};
