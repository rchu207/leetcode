class Solution {
public:
    bool isPalindrome(int x) {
        int y = 0;
        int z = x;

        if (x < 0)
            return false;

        while (x >= 10) {
            y += x % 10;
            y *= 10;
            x /= 10;
        }
        y += x;
        
        return (z == y);
    }
};
