import java.util.HashMap;

public class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> dpTable = new HashMap<>(1000);
        int[] result = new int[2];

        for (int i = 0; i < nums.length; i++) {
            int remain = target - nums[i];
            if (dpTable.containsKey(remain)) {
                result[0] = dpTable.get(remain);
                result[1] = i;
                return result;
            }
            dpTable.put(nums[i], i);
        }

        return result;
    }
}
