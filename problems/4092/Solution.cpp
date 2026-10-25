// 4092. Binary Digit Score

class Solution {
public:
    int calculateScore(int a, int b) {
        auto s1 = getSetBitNumber(a);
        auto s2 = getSetBitNumber(b);
        if (s1 >= s2)
            return s1 * s2;
        else if (s1 > 0)
            return s2 / s1;
        else
            return 0;
    }

    int getSetBitNumber(int n) {
        int number = 0;
        while (n >= 2) {
            number = number + (n & 0x1);
            n = n >> 1;
        }
        return number + (n & 0x1);
    }
};
