

object Solution {
    def checkSubarraySum(nums: Array[Int], k: Int): Boolean = {

        import scala.util.control.Breaks._

        val seen = scala.collection.mutable.Set[Int]()
        var running = 0
        var mod = 0
        var res = false
        breakable {
            for (n <- nums) {
                running += n
                val tmp = running % k
                if (seen.contains(tmp)) {
                    res = true
                    break()
                }
                seen.add(mod)
                mod = tmp
            }
        }
        res
    }
}
