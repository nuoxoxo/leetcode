object Solution {
    def appendCharacters(s: String, t: String): Int = {
        var si = 0
        var ti = 0
        var lens = s.length
        var lent = t.length
        while (si < lens) {
            if (s(si) == t(ti)) {
                ti += 1
                if (ti == lent)
                    return 0
            }
            si += 1
        }
        lent - ti
    }
}
