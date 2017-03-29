class Solution {
    func lengthOfLongestSubstring(_ s: String) -> Int {
        var longestLength = 0
        var map = [Character: Int]()
        var i = 0, j = 0
        
        for c in s.characters {
            if let next = map[c] {
                if j - i > longestLength {
                    longestLength = j - i
                }
                if next + 1 > i {
                    i = next + 1
                }
            }
            map[c] = j
            j += 1
        }
        
        if s.characters.count - i > longestLength {
            longestLength = s.characters.count - i
        }
        return longestLength
    }
}
