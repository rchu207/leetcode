// 4030. Check ASCII Palindromic

class Solution {
public:
    bool isPalindromic(string s) {
        int start = 0;
        int end = s.size() - 1;
        while (start <= end) {
            vector<char> binary1(8);
            vector<char> binary2(8);
            toBinaries(s[start], binary1);
            toBinaries(s[end], binary2);
            if (checkPalindrome(binary1, binary2)) {
                start++;
                end--;
            } else {
                return false;
            }
        }

        return true;
    }

private:
    void toBinaries(char c, vector<char>& binaries) {
        int tmp = 1 << 7;
        for (int i = 0; i < 8; i++) {
            if ((c & tmp) > 0) {
                binaries[i] = '1';
            } else {
                binaries[i] = '0';
            }
            tmp = tmp >> 1;
        }
    }

    bool checkPalindrome(vector<char>& binary1, vector<char>& binary2) {
        int n = binary1.size();
        for (int i = 0; i < n; i++) {
            if (binary1[i] != binary2[n - 1 - i]) {
                return false;
            }
        }
        return true;
    }
};
