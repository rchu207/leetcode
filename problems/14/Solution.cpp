// 14. Longest Common Prefix

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string answer = "";
        int minLength = strs[0].length();
        for (int i = 1; i < strs.size(); i++) {
            if (strs[i].length() < minLength) {
                minLength = strs[i].length();
            }
        }
        for (int j = 0; j < minLength; j++) {
            auto c = strs[0][j];
            for (int i = 1; i < strs.size(); i++) {
                if (c != strs[i][j]) {
                    return answer;
                }
            }
            answer += c;
        }
        return answer;
    }
};
