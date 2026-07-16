// 151. Reverse Words in a String

class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        int left = 0;
        int right = 0;

        while (right < n) {
            if (s[right] == ' ') {
                right++;
                continue;
            }
            if (left != 0)
                s[left++] = ' ';
            while (right < n && s[right] != ' ') {
                s[left++] = s[right++];
            }
        }
        s.resize(left);
        n = left;

        std::reverse(s.begin(), s.end());

        left = 0;
        while (left < n) {
            right = left;
            while (right < n && s[right] != ' ')
                right++;
            std::reverse(s.begin() + left, s.begin() + right);
            left = right + 1;
        }

        return s;
    }
};
