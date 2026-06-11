// 350. Intersection of Two Arrays II

class Solution {
private:
    vector<int> bruteForce(vector<int>& nums1, vector<int>& nums2) {
        vector<int> answer;
        for (auto& v : nums1) {
            auto iter = std::find(nums2.begin(), nums2.end(), v);
            if (iter != nums2.end()) {
                answer.push_back(v);
                nums2.erase(iter);
            }
        }
        return answer;
    }
    
    vector<int> sortAndFind(vector<int>& nums1, vector<int>& nums2) {
        int index1 = 0;
        int n1 = nums1.size();
        int index2 = 0;
        int n2 = nums2.size();
        vector<int> answer;

        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());

        while (index1 < n1 && index2 < n2) {
            if (nums1[index1] == nums2[index2]) {
                answer.push_back(nums1[index1]);
                index1++;
                index2++;
            } else if (nums1[index1] < nums2[index2]) {
                index1++;
            } else {
                index2++;
            }
        }
        return answer;
    }
    
    vector<int> useHashMap(vector<int>& nums1, vector<int>& nums2) {
        vector<int> answer;
        map<int, int> table1;
        
        for (auto& v : nums1) {
            table1[v]++;
        }
        for (auto& v : nums2) {
            if (table1[v] > 0) {
                answer.push_back(v);
                table1[v]--;
            }
        }
        
        return answer;
    }
    
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        // return bruteForce(nums1, nums2);
        // return sortAndFind(nums1, nums2);
        if (nums1.size() < nums2.size()) {
            return useHashMap(nums1, nums2);
        } else {
            return useHashMap(nums2, nums1);
        }
    }
};
