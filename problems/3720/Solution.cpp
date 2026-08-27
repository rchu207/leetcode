// 3720. Lexicographically Smallest Permutation Greater Than Target

class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.length();
        vector<int> letters(26, 0);

        for (auto& c : s) {
            letters[c - 'a']++;
        }

        vector<char> answer(n, 0);
        auto found = permutation(n, letters, 0, target, false, answer);
        if (found) {
            return string(answer.begin(), answer.end());
        } else {
            return "";
        }
    }

    bool permutation(int n, vector<int>& letters, int index, string& target, bool greater, vector<char>& answer) {
        if (index == n) {
            return greater;
        }

        int start = (greater) ? 0 : target[index] - 'a';
        for (int t = start; t < 26; t++) {
            if (letters[t] <= 0) {
                continue;
            }
            answer[index] = t + 'a';
            bool greater2 = greater || (answer[index] > target[index]);
            letters[t]--;
            if (permutation(n, letters, index + 1, target, greater2, answer)) {
                return true;
            }
            letters[t]++;
        }
        return false;
    }
};
