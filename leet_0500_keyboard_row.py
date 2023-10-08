class Solution:
    def findWords(self, words: List[str]) -> List[str]:
        def checker(charset: str, word: str):
            for c in word:
                if c.lower() not in charset:
                    print(c, word)
                    return False
            return True
        res = []
        for w in words:
            if checker('qwertyuiop', w) or checker('asdfghjkl', w) or checker('zxcvbnm', w):
                res.append(w)
        return res
