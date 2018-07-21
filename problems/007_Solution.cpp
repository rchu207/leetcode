class Solution {
public:
    int reverse(int x) {
        int minus = 1;
        int digit[10] = {};
        int max[10] = {7, 4, 6, 3, 8, 4, 7, 4, 1, 2};
        //int max[10] = {2, 1, 4, 7, 4, 8, 3, 6, 4, 7};
        int y, z;
        int i, j;
        bool pass;
        
        // if (x < 0) {
        //     x *= -1;
        //     minus = -1;            
        // }

        i = 0;
        if (x >= 0) {
            while (x >= 10) {
                digit[i] = x % 10;
                x /= 10;
                i++;
            }
            digit[i] = x;            
        } else {
            while (x <= -10) {
                digit[i] = (x % 10) * -1;
                x /= 10;
                i++;
            }
            digit[i] = x * -1;      
            minus = -1;
        }
        
        for (j = 0; j <= i/2; j++) {
            z = digit[j];
            digit[j] = digit[i-j];
            digit[i-j] = z;
        }
                
        y = 0;
        z = 1000000000;
        for (j = 9; j >= 0; j--) {
            y += digit[j] * z;
            z /= 10;
        }
        y *= minus;

        pass = false;
        for (j = 9; j >= 0; j--) {
            if (digit[j] > max[j]) {
                pass = false;
                break;
            } else if (digit[j] < max[j]) {
                pass = true;
                break;
            }
        }
        
        if (pass)
            return y;
        else
            return 0;
    }
};
