impl Solution {
    pub fn longest_subarray(nums: Vec<i32>) -> i32 {
        let mut tt: i32 = 1;
        let mut L: i32 = 0;
        let mut R: i32 = -1;
        while R < (nums.len() as i32 - 1) {
            R += 1;
            if nums[R as usize] == 0 {
                tt -= 1;
            }
            if tt < 0 {
                if nums[L as usize] == 0 {
                    tt += 1;
                }
                L += 1;
            }
        }
        return nums.len() as i32 - 1 - L;
    }
}
