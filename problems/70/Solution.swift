class Solution {
    func climbStairs(_ n: Int) -> Int {
        var steps = [1, 1]
        if n >= 2 {
            for i in 2...n {
                steps.append(steps[i-1] + steps[i-2])
            }
        }
        return steps[n]
    }
}
