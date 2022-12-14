// The API isBadVersion is defined for you.
// isBadVersion(version:i32)-> bool;
// to call it use self.isBadVersion(version)

impl Solution {
    pub fn first_bad_version(&self, n: i32) -> i32
    {
		let mut l: i32 = 1;
        let mut r: i32 = n;

        while (l <= r)
        {
            let     mid: i32 = l + (r - l) / 2;

            if (self.isBadVersion(mid)) {
                r = mid - 1;
            } else {
                l = mid + 1
            }
        }
        return l;
    }
}
