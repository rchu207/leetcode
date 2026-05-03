class Solution {
private:
    bool isPrime(int i) {
        for (int k = 2; k * k <= i; k++) {
            if (i % k == 0)
                return false;
        }
        return (i > 1);
    }

public:
    int sumOfPrimesInRange(int n) {
        int r = 0;
        auto tmp = n;
        while (tmp >= 10) {
            r += tmp % 10;
            r *= 10;
            tmp = tmp / 10;
        }
        r += tmp;


        int sum = 0;
        for (int i = std::min(n, r); i <= std::max(n, r); i++) {
            if (isPrime(i))
                sum += i;
        }
        return sum;
    }
};
