class Solution {
    func longestCommonPrefix(_ strs: [String]) -> String {
        if strs.count == 0 {
            return ""
        }

        for i in 0..<strs[0].characters.count {
            let index = strs[0].index(strs[0].startIndex, offsetBy: i)
            let target = strs[0][index]
            for j in 1..<strs.count {
                if i == strs[j].characters.count || strs[j][index] != target {
                    return strs[0].substring(to: index)
                }
            }

        }

        return strs[0]
    }
}
