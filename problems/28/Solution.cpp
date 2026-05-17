class Solution {
public:
    int strStr(string haystack, string needle) {
        int i, j;
        
        if (needle.length() == 0)
            return 0;
        
        for (i = 0; i <= (int)haystack.length() - (int)needle.length(); i++) {
            for (j = 0; j < needle.length(); j++)
                if (haystack[i + j] != needle[j])
                    break;
            
            if (j == needle.length())
                return i;
        }
        
        return -1;
    }
};
