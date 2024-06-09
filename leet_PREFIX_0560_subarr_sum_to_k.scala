object Solution {

    /*

    a subarr can be expressed this way
    -> a0 + a1 + a2 + ... + a[i - 1] + ai + ... + aj
    ->                                 ^^^^^^^^^^^^^ = f(j) - f(i - 1)

    BECAUSE, in terms of line segment
    -> ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ = f(j)
    -> ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ = f(i - 1)

    SO a subarr sums to k IF :
    -> f(j) - f(i - 1) === k, ... from which we can have
    -> f(j) - k === f(i - 1) ... this is what we want
    -> so, keeping track of DICT[f(j) - k] == counting how many such subarrays

    */

    def subarraySum(nums: Array[Int], k: Int): Int = {

        var res = 0
        var running = 0
        var prefix = scala.collection.mutable.Map[Int, Int]().withDefaultValue(0)
        prefix(0) = 1
        for (n <- nums) {
            running += n
            res += prefix(running - k)
            prefix(running) += 1
        }
        res
    }
}
