// 771. Jewels and Stones
class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<char, bool> hashmap;
        for (auto& c : jewels) {
            hashmap[c] = true;
        }
        int answer = 0;
        for (auto& c : stones) {
            if (hashmap[c])
                answer++;
        }
        return answer;
    }
};
