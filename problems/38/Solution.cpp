class Solution {
public:
    string countAndSay(int n) {
        string result;
        string temp;
        int i, j, k;
        
        result = "1";
        for (i = 2; i <= n; i++) {
            temp = "";
            j = 0;
            while (j < result.length()) {
                for (k = j + 1; k < result.length(); k++)
                    if (result[j] != result[k])
                        break;
                temp = temp + (char)('0' + (k - j)) + result[j];
                j = k;
            }
            
            result = temp;
        }
        
        return result;
    }
};
