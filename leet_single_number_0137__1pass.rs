impl Solution {
    pub fn single_number(nums: Vec<i32>) -> i32 {
        let len = nums.len();
        if len == 1 {
            return nums[0];
        }
        let mut n = nums;
        n.sort();
        if n[0] ^ n[1] != 0 {
            return n[0];
        }
        let mut i = 0;
        while i < len - 2 {
            if n[i] != n[i + 1] && n[i + 1] != n[i + 2] {
                break;
            }
            i += 1;
        }
        return n[i + 1];
    }
}
