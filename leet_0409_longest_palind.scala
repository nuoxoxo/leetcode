object Solution {
    def longestPalindrome(s: String): Int = {
        val arr = new Array[Int](123)
        for (c <- s.toArray) {
            // println(c)
            arr(c) += 1
        }
        var res = 0
        var mid = 0
        // println(D.mkString(" "))
        for (n <- arr) {
            if (n % 2 == 1) {
                mid = 1
                res += n - 1
            } else {
                res += n
            }
        }
        if (mid == 1) {
            res += 1
        }
        res
    }
}
