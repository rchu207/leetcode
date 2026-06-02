// 599. Minimum Index Sum of Two Lists

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> hashmap;
        
        for (int i = 0; i < list1.size(); i++) {
            hashmap[list1[i]] = i + 10000;
        }
        for (int i = 0; i < list2.size(); i++) {
            if (hashmap.count(list2[i]) > 0) {
                hashmap[list2[i]] += (i - 10000);
            }
        }
        
        vector<string> answer;
        int leastSum = 20000;
        for (const auto& iter : hashmap) {
            if (iter.second == leastSum) {
                answer.push_back(iter.first);
            } else if (iter.second < leastSum) {
                answer.clear();
                answer.push_back(iter.first);
                leastSum = iter.second;
            }
        }
        return answer;
    }
};
