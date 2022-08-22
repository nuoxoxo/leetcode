impl Solution {
    pub fn is_power_of_four(n: i32) -> bool {
        let mut n = n;
        if n < 1 {
            false
        } else {
            while n % 4 == 0 {
                n /= 4
            }
            n == 1
        }
    }
}
