object Solution {
    def minPatches(nums: Array[Int], n: Int): Int = {
        var res = 0
        var R = 0L // eq. long long - i64
        for (num <- nums) {
            while (R < n && R + 1 < num) {
                R += R + 1
                res += 1
            }
            R += num
        }
        while (R < n) {
            R += R + 1
            res += 1
        }
        res
    }
}
