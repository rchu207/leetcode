// 3. Longest Substring Without Repeating Characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int left = 0;
        int right = 0;
        unordered_map<char, int> hashmap;   // character, right position
        int answer = 0;
        while (right < n) {
            if (hashmap.count(s[right]) > 0 && hashmap[s[right]] >= left) {
                left = hashmap[s[right]] + 1;
            }
            answer = std::max(answer, right - left + 1);
            hashmap[s[right]] = right;
            right++;
        }
        return answer;
    }
};
