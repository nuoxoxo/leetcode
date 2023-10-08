impl Solution {
    pub fn majority_element(nums: Vec<i32>) -> Vec<i32> {

        let mut res = Vec::new();
        let (mut l, mut lc, mut r, mut rc) = (0, 0, 0, 0);

        for n in nums.iter() {

            if l == *n {
                lc += 1;
            } else if r == *n {
                rc += 1;
            } else if lc == 0 {
                lc = 1;
                l = *n;
            } else if rc == 0 {
                rc = 1;
                r = *n;
            } else {
                lc -= 1;
                rc -= 1;
            }
        }

        lc = 0;
        rc = 0;
        for n in nums.iter() {
            if *n == l {
                lc += 1;
            } else if *n == r {
                rc += 1;
            }
        }

        if lc > nums.len() / 3 {
            res.push(l);
        }
        if rc > nums.len() / 3 {
            res.push(r);
        }

        res
    }
}
