impl Solution {
    pub fn kth_grammar(n: i32, k: i32) -> i32 {
        let mut L = 1;
        let mut R = 2_i32.pow((n - 1) as u32);
        let mut res = 0;
        for _ in 0..(n - 1) {
            let mid = (R - L) / 2 + L;
            if mid < k {
                L = mid + 1;
                res ^= 1;
            } else {
                R = mid;
            }
        }
        res
    }
}
