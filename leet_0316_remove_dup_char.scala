object Solution {
    def removeDuplicateLetters(s: String): String = {
        val seen = Array.fill(26)(false)
        val count = Array.fill(26)(0)
        var res = ""
        val a = 'a'.toInt
        for (c <- s) {
            count(c.toInt - a) += 1
        }
        for (c <- s) {
            val asc = c.toInt - a
            if ( !seen(asc)) {
                while (res.nonEmpty && res.last > c && count(res.last.toInt - a) > 1) {
                    seen(res.last.toInt - a) = false
                    count(res.last.toInt - a) -= 1
                    res = res.init
                }
                seen(asc) = true
                res += c
            } else {
                count(asc) -= 1
            }
        }
        res
    }
}
