object Solution {
    def isAnagram(s: String, t: String): Boolean = {
        s.sorted.equals(t.sorted)
    }
}
