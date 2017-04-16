class Solution {
    func removeElement(_ nums: inout [Int], _ val: Int) -> Int {
        var length = 0
        for i in 0..<nums.count {
            if nums[i] != val {
                nums[length] = nums[i]
                length += 1
            }
        }
        
        return length
    }
}
