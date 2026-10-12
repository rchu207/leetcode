// 4078. Three Fibonacci Sum

class Solution {
public:
    bool threeFibonacciSum(int n) {
        if (n % 2) {
            // odd number, no answer
            return false;
        }

        int a = 1;
        int b = 1;
        while (b < n / 2) {
            auto t = a + b;
            a = b;
            b = t;
        }
        return (b == n / 2);
    }
};
