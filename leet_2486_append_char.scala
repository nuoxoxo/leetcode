object Solution {
    def appendCharacters(s: String, t: String): Int = {
        val solutions: List [(String, String) => Int] = List (
            // Iterative, // best
            Recursive,
        )
        solutions.head(s, t)
    }

    def Recursive (s: String, t: String): Int = {

        val lens = s.length
        val lent = t.length

        def go (is: Int, it: Int): Int = {
            if (it == lent)
                return 0
            if (is == lens)
                return lent - it
            if (s(is) == t(it))
                return go(is + 1, it + 1)
            go(is + 1, it)
        }

        go(0, 0)
    }

    def Iterative (s: String, t: String): Int = {

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
