impl Solution {
    pub fn min_patches(nums: Vec<i32>, n: i32) -> i32 {
        let mut res = 0;
        let mut R:i64 = 0;
        for & num in nums.iter() {
            while R < n as i64 && R + 1 < num as i64 {
                R = R * 2 + 1;
                res += 1;
            }
            R += num as i64;
        }
        while R < n as i64 {
            R = R * 2 + 1;
            res += 1;
        }
        res
    }
}
