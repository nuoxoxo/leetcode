impl Solution {
    pub fn min_pair_sum(nums: Vec<i32>) -> i32 {
        let mut n: Vec<i32> = nums.iter().cloned().collect();
        // let mut n = Vec::from(nums);
        // let mut n = nums.to_owned();
        // let mut n = nums.to_vec();

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
