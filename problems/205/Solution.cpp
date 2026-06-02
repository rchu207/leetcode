// 205. Isomorphic Strings

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> hashmap;
        unordered_map<char, char> hashmap2;
        
        int n = s.length();
        for (int i = 0; i < n; i++) {
            auto c = s[i];
            auto c2 = t[i];
            if (hashmap.count(c) > 0) {
                if (hashmap[c] != c2)
                    return false;
            } else if (hashmap2.count(c2) > 0) {
                if (hashmap2[c2] != c)
                    return false;
            } else {
                hashmap[c] = c2;
                hashmap2[c2] = c;
            }
        }
        
        return true;
    }
};
