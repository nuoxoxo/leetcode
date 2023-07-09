impl Solution {
    pub fn min_operations(nums: Vec<i32>) -> i32 {
        let mut nums = nums;
        let mut res = 0;
        let mut i = 0;

        while i < nums.len() - 1 {

            i += 1;
            if nums[i - 1] < nums[i] {
                continue;
            }
            let temp = nums[i - 1] - nums[i] + 1;
            res += temp;
            nums[i] = nums[i - 1] + 1;

        }
        res
    }
}
