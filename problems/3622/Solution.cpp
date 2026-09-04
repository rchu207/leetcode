// 3622. Check Divisibility by Digit Sum and Product

class Solution {
public:
    bool checkDivisibility(int n) {
        int tmp = n;
        int sum = 0;
        int product = 1;
        while (tmp >= 10) {
            auto digit = tmp % 10;
            sum += digit;
            product *= digit;
            tmp = tmp / 10;
        }
        sum += tmp;
        product *= tmp;
        return (n % (sum + product) == 0);
    }
};
