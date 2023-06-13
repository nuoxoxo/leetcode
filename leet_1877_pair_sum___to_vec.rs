impl Solution {
    pub fn min_pair_sum(nums: Vec<i32>) -> i32 {
        let mut n = nums.to_vec();
        // let mut n = nums.to_owned();

        n.sort();
        let len = n.len();
        let mut res = std::i32::MIN;
        let mut i = 0;
        while i < len {
            res = res.max(n[i] + n[len - i - 1]);
            i += 1;
        }
        res
    }
}
