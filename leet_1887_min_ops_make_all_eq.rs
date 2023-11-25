impl Solution {
    pub fn reduction_operations(nums: Vec<i32>) -> i32 {
        /*
        let mut nums = nums;
        nums.sort();
        let mut i = 1;
        let mut res = 0;
        let mut dist = 0;
        while i < nums.len() {
            if nums[i] != nums[i - 1] {
                dist += 1;
            }
            res += dist;
            i += 1;
        }
        res
        */

        let mut nums = nums;
        nums.sort();
        let mut i = 1;
        let mut res = 0;
        while i < nums.len() {
            if nums[i] != nums[i - 1] {
                res += (nums.len() - i) as i32 // strangely no ';' needed here
            }
            i += 1;
        }
        res
    }
}
