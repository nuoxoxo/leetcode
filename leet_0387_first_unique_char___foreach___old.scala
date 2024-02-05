object Solution {
    def firstUniqChar(s: String): Int = {
        var dp = Array.fill[Int](26)(0)
        var i = 0

        s.foreach {
            c => dp(c - 'a') += 1
        }
        
        s.foreach {
            c => if (dp(c - 'a') == 1) {
                return i
            }
            i += 1
        }
        -1
    }
}
