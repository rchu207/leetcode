package tw.idv.rchu.leetcode;

public class Solution {
    public int removeDuplicates(int[] nums) {
        int length = 0;
        for (int i = 0; i < nums.length; i++) {
            if (length == 0) {
                nums[0] = nums[i];
                length++;
            } else if (nums[i] != nums[length - 1]) {
                nums[length] = nums[i];
                length++;
            }
        }

        return length;
    }
}
