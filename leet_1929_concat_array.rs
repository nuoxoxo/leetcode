impl Solution {
    pub fn get_concatenation(nums: Vec<i32>) -> Vec<i32> {
        let mut res = vec![0; nums.len() * 2];
        nums.iter().enumerate().for_each(
            |(i, &x)| {
                res[i] = x;
                res[i + nums.len()] = x;
            }
        );
        res
    }
}
