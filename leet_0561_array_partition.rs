impl Solution {
    pub fn array_pair_sum(nums: Vec<i32>) -> i32 {
        let mut n = nums.clone();
        let mut res = 0;

        n.sort();
        // res = 0;
        for (i, x) in n.iter().enumerate() {
            if i % 2 == 0 {
                res += x;
            }
        }
        res
    }
}
