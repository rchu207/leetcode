// 3932. Count K-th Roots in a Range

class Solution {
public:
    int countKthRoots(int l, int r, int k) {
        auto lroot = getRoot(l, k, 2, 1);
        auto rroot = getRoot(r, k, lroot, -1);

        if (rroot >= lroot)
            return rroot - lroot + 1;
        else
            return 0;
    }

private:
    int getRoot(int y, int k, int start, int bound) {
        if (k == 1)
            return y;

        for (int x = start; x <= y; x++) {
            long long product = fastProduct(x, k);
            
            if (product == y) {
                return x;
            } else if (product > y) {
                if (bound > 0) {
                    return x;
                } else {
                    return x - 1;
                }
            }
        }
        return y;
    }

    long long fastProduct(int x, int k) {
        if (k == 0)
            return 1;
        else if (k == 1)
            return x;

        auto tmp = fastProduct(x, k / 2);
        if (k % 2 == 1) {
            return tmp * tmp * x;
        } else {
            return tmp * tmp;
        }
    }
};
