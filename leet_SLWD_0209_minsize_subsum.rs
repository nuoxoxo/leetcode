impl Solution {
    pub fn min_sub_array_len(target: i32, nums: Vec<i32>) -> i32 {
        if nums.contains(&target) {
            return 1;
        }
        let mut l = 0;
        let mut r = 0;
        let mut found = false;
        let mut res = i32::MAX;
        let mut temp = 0;
        let len = nums.len();
        while r < len {
            temp += nums[r];
            if temp >= target {
                found = true;
            }
            while temp >= target {
                res = res.min((r - l + 1) as i32);
                temp -= nums[l];
                l += 1;
            }
            r += 1;
        }
        if !found {
            return 0;
        }
        res
    }
}
