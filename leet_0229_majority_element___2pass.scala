object Solution {
    def majorityElement(nums: Array[Int]): List[Int] = {

        var res = List[Int]()
        var (l, lc, r, rc) = (0, 0, 0, 0)

        for (n <- nums) {
            if (l == n) {
                lc += 1
            } else if (r == n) {
                rc += 1
            } else if (lc == 0) {
                lc = 1
                l = n
            } else if (rc == 0) {
                rc = 1
                r = n
            } else {
                lc -= 1
                rc -= 1
            }
        }

        lc = 0
        rc = 0
        for (n <- nums) {
            if (n == l) {
                lc += 1
            } else if (n == r) {
                rc += 1
            }
        }

        if (lc > nums.length / 3) {
            res = l :: res
        }
        if (rc > nums.length / 3) {
            res = r :: res
        }

        res
    }
}
