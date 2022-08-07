object Solution {
    def combinationSum4(nums: Array[Int], target: Int): Int = {
        // var dp = new Array.fill[Int](target + 1)(0);
        var dp = Array.fill[Int](target + 1)(0);
        dp(0) = 1;
        for (i <- 1 to target) // for loop in scala: upper limit is included
        {
            for (n <- nums)
            {
                if (i - n > -1)
                {
                    dp(i) += dp(i - n);
                }
            }
        }
        dp(target)
    }
}
