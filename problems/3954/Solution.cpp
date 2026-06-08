// 3954. Sum of Compatible Numbers in Range I

class Solution {
public:
    int sumOfGoodIntegers(int n, int k) {
        int lower = (n > k) ? n - k : 1;
        int upper = n + k;
        int sum = 0;
        for (int x = lower; x <= upper; x++) {
            if ((x & n) == 0)
                sum += x;
        }
        return sum;
    }
};
