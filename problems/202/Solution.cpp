// 202. Happy Number

class Solution {
    long long next(long long n) {
        long long result = 0;
        while (n > 0) {
            auto digit = n % 10;
            result += digit * digit;
            n /= 10;
        }
        return result;
    }

public:
    bool isHappy(int n) {
        long long slow = next(n);
        long long fast = next(next(n));

        while (slow != fast) {
            slow = next(slow);
            fast = next(next(fast));
        }

        return slow == 1;
    }
};
