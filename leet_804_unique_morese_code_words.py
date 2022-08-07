class Solution:
    def uniqueMorseRepresentations(self, words: List[str]) -> int:
        E = set()
        for s in words:
            E.add( self.mc(s) )
        return len(E)

    def mc(self, s: str) -> str:
        morse = [".-","-...","-.-.","-..",".","..-.","--.",\
                 "....","..",".---","-.-",".-..","--","-.",\
                 "---",".--.","--.-",".-.","...","-","..-",\
                 "...-",".--","-..-","-.--","--.."]
        res = ""
        for c in s:
            res += morse[ord(c) - ord('a')]
        return res
