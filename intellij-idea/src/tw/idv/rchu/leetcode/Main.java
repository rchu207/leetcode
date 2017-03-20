package tw.idv.rchu.leetcode;

public class Main {

    public static void main(String[] args) {
        int[] nums = new int[4];
        nums[0] = 2;
        nums[1] = 7;
        nums[2] = 11;
        nums[3] = 15;
        Solution solution = new Solution();
        int[] result = solution.twoSum(nums, 9);
        System.out.println(result[0] + "," + result[1]);
    }
}
