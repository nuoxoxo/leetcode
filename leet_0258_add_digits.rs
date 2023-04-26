impl Solution {
    pub fn add_digits(num: i32) -> i32 {
        let mut n = num;
        while n > 9 {
            n = Solution::helper(n);
        }
        n
    }

    pub fn helper(num: i32) -> i32 {
        let mut n = num;
        let mut res = 0;
        while n > 0 {
            res += n % 10;
            n /= 10;
        }
        res
    }
}
