// 349. Intersection of Two Arrays

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> group; 
        for (auto& v : nums1) {
            group.insert(v);
        }

        vector<int> result;
        for (int i = 0; i < nums2.size(); i++) {
            if (group.count(nums2[i]) == 1) {
                result.push_back(nums2[i]);
                group.erase(nums2[i]);
            }
        }
        return result;
    }
};
