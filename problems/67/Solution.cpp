// 67. Add Binary

class Solution {
public:
    string addBinary(string a, string b) {
        if (a.length() < b.length()) {
            string tmp = a;
            a = b;
            b = tmp;
        }

        string result = "";
        int i = a.length() - 1;
        int more = 0;
        for (int j = b.length() - 1; j >= 0; i--, j--) {
            int sum = (a[i] - '0') + (b[j] - '0') + more;
            if (sum == 0) {
                result += "0";
                more = 0;
            } else if (sum == 1) {
                result += "1";
                more = 0;
            } else if (sum == 2) {
                result += "0";
                more = 1;
            } else {
                result += "1";
                more = 1;
            }
        }
        for (; i >= 0; i--) {
            int sum = (a[i] - '0') + more;
            if (sum == 0) {
                result += "0";
                more = 0;
            } else if (sum == 1) {
                result += "1";
                more = 0;
            } else if (sum == 2) {
                result += "0";
                more = 1;
            } else {
                result += "1";
                more = 1;
            }                
        }
        if (more == 1) {
            result += "1";
        }
        // reverse
        std::reverse(result.begin(), result.end());
        return result;
    }
};
