object Solution {
    def scoreOfString(s: String): Int = {
        val Solutions: List [(String) => Int] = List (
            // Straightforward,
            // Oneliner_zip,
            Oneliner_sliding,
        )
        Solutions.head(s)
    }

    def Oneliner_sliding(s: String) : Int = 
        s.map(_.toInt).sliding(2).map(pair => Math.abs(pair.head - pair(1))).sum

    def Oneliner_zip(s: String) : Int = {
        // s    -> "Hello"
        // s.tail -> "ello"
        // s.zip(s.tail)
        //  -> Vector(('h', 'e'), ('e', 'l'), ('l', 'l'), ('l', 'o'))
        s.zip(s.tail).map(pair => Math.abs(pair._1 - pair._2)).sum
    }

    def Straightforward(s: String) : Int = {
        var res = 0
        var N = s.length
        for (i <- 0 until N - 1) {
            var tmp = s(i).toInt - s(i + 1).toInt
            res += Math.abs(tmp)
        }
        res
    }
}
