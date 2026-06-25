// 454. 4Sum II

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int n = nums1.size();
        unordered_map<long long, int> hashmap;
        int answer = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                auto sum = nums1[i] + nums2[j];
                hashmap[sum]++;
            }
        }
        for (int k = 0; k < n; k++) {
            for (int l = 0; l < n; l++) {
                auto sum = -1 * (nums3[k] + nums4[l]);
                answer += hashmap[sum];
            }
        }
        return answer;
    }
};
