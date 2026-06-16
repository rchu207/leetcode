// 3959. Check Good Integer

class Solution {
public:
    bool checkGoodInteger(int n) {
        long long digitSum = 0;
        long long squareSum = 0;
        while (n >= 10) {
            auto d = n % 10;
            n = n / 10;
            digitSum += d;
            squareSum += d * d;            
        }
        digitSum += n;
        squareSum += n * n;
        return (squareSum - digitSum >= 50);
    }
};
