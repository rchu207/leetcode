// 3982. Sum of Integers with Maximum Digit Range

class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        map<int, int> hashmap;
        for (auto& n : nums) {
            int largest = -1;
            int smallest = 10;
            int v = n;
            while (v >= 10) {
                auto d = v % 10;
                if (d > largest) {
                    largest = d;
                }
                if (d < smallest) {
                    smallest = d;
                }
                v = v / 10;
            }
            auto d = v % 10;
            if (d > largest) {
                largest = d;
            }
            if (d < smallest) {
                smallest = d;
            }
            auto r = largest - smallest;
            hashmap[r] += n;
        }

        auto answer = hashmap.end();
        answer--;
        return answer->second;
    }
};
