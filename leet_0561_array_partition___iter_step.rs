impl Solution {
    pub fn array_pair_sum(nums: Vec<i32>) -> i32 {
        let mut n = nums.clone();
        let mut res = 0;

        n.sort();
        n.iter().step_by(2).sum()
    }
}
