object Solution {

    import scala.collection.mutable.ArrayBuffer // .swap

    def sortColors(nums: Array[Int]): Unit = {

        val N = nums.length
        var l = 0
        var r = N - 1
        while (l < N && nums(l) == 0) {
            l += 1
        }
        while (r > -1 && nums(r) == 2) {
            r -= 1
        }
        var mid = l
        while (mid < r + 1) {
            if (nums(mid) == 0) {
                val temp = nums(mid)
                nums(mid) = nums(l)
                nums(l) = temp
                l += 1
            } else if (nums(mid) == 2) {
                val temp = nums(mid)
                nums(mid) = nums(r)
                nums(r) = temp
                r -= 1
                mid -= 1
            }
            mid += 1
        }
    }
}
