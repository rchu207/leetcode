class Solution {
    func twoSum(_ nums: [Int], _ target: Int) -> [Int] {
        var dpTable = [Int: Int]()
        
        for i in 0..<nums.count {
            let remain = target - nums[i];
            if let j = dpTable[remain] {
                return [j, i]
            }
            dpTable[nums[i]] = i
        }
        return [0, 0]
    }
}
