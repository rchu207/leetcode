// 4043. Count Rotations With Exactly K Equal Adjacent Pairs

class Solution {
public:
    int countRotations(string s, int k) {
        int n = s.length();
        int answer = 0;

        int score = 0;
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1])
                score++;
        }
        if (score == k) {
            answer++;
        }

        for (int j = 1; j < n; j++) {
            if (s[j - 1] == s[j])
                score--;
            if (j - 2 >= 0) {
                if (s[j - 2] == s[j - 1])
                    score++;
            } else {
                if (s[n - 1] == s[j - 1])
                    score++;
            }
            if (score == k)
                answer++;
        }
    
        return answer;
    }
};