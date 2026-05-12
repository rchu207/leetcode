// 3926. Count Valid Word Occurrences
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;


class Solution {
public:
    vector<int> countWordOccurrences(vector<string>& chunks, vector<string>& queries) {
        string s;
        for (auto& chunk : chunks) {
            s += chunk;
        }

        unordered_map<string, int> freq;
        string word;
        auto flush = [&]() {
            if (!word.empty()) {
                freq[word]++;
                word.clear();
            }
        };

        int n = s.size();
        for (int i = 0; i < n; i++) {
            char c = s[i];
            if (c >= 'a' && c <= 'z') {
                word += c;
            } else if (c == '-') {
                // joiner hyphen: both neighbors must be lowercase letters
                bool joiner = i > 0 && i + 1 < n
                    && s[i-1] >= 'a' && s[i-1] <= 'z'
                    && s[i+1] >= 'a' && s[i+1] <= 'z';
                if (joiner) {
                    word += c;
                } else {
                    flush();
                }
            } else {
                flush();
            }
        }
        flush();

        vector<int> ans;
        for (auto& q : queries) {
            auto it = freq.find(q);
            ans.push_back(it != freq.end() ? it->second : 0);
        }
        return ans;
    }
};
