class Solution:
    def uniqueMorseRepresentations(self, words: List[str]) -> int:
        def matching(s : str) -> str:
            morseset = [
                ".-","-...","-.-.","-..",".","..-.","--.", \
                "....","..",".---","-.-",".-..","--","-.", \
                "---",".--.","--.-",".-.","...","-","..-", \
                "...-",".--","-..-","-.--","--.."
            ]
            res = ""
            a = ord('a')
            for c in s:
                res += morseset[ord(c) - a]
            return res
        strset = set()
        for s in words:
            strset.add(matching(s))
        return len(strset)

"""        
a-z mapping:

".-",
"-...",
"-.-.",
"-..",
".",
"..-.",
"--.",
"....",
"..",
".---",
"-.-",
".-..",
"--",
"-.",
"---",
".--.",
"--.-",
".-.",
"...",
"-",
"..-",
"...-",
".--",
"-..-",
"-.--",
"--.."
"""
