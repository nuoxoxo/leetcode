// The API isBadVersion is defined for you.
// isBadVersion(version:i32)-> bool;
// to call it use self.isBadVersion(version)

impl Solution {
    pub fn first_bad_version(& self, n: i32) -> i32 {
		Solution::binary_search(&self, 0, n, n)
    }

    fn binary_search(&self, l: i32, r: i32, curr: i32) -> i32 {
        if l > r 
        {
            return curr;
        }
        let mid: i32 = l + (r - l) / 2;
        if self.isBadVersion(mid) 
        {
            return Solution::binary_search(&self, l, mid - 1, mid)
        }
        Solution::binary_search(&self, mid + 1, r, curr)
    }
}
