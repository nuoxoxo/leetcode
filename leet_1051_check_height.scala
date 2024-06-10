object Solution {
    def heightChecker(heights: Array[Int]): Int = {
        var sorted = heights.sorted
        (sorted zip heights).count { case (l, r) => l != r }
    }
}
