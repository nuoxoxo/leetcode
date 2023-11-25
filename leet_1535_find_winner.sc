object Solution {
    def getWinner(arr: Array[Int], k: Int): Int = {
        val hi = arr.max
        val len = arr.length
        if (len <= k) {
            return hi
        }
        var count = 0
        var res = arr(0)
        var i = 1
        while (i < len) {
            if (res < arr(i)) {
                count = 1
                res = arr(i)
            } else {
                count += 1
            }
            if (count == k) {
                return res
            }
            i += 1
        }
        return hi
    }
}
