class Solution:
    def findAndReplacePattern(self, words: List[str], pattern: str) -> List[str]:
        def valid (w: str, p: str) -> bool:
            www = [-1] * 26
            ppp = [-1] * 26
            for i in range(len(w)):
                wc = w[i]
                pc = p[i]
                a = ord('a')
                if www[ord(wc) - a] == -1:
                    www[ord(wc) - a] = pc
                if ppp[ord(pc) - a] == -1:
                    ppp[ord(pc) - a] = wc
                if www[ord(wc) - a] != pc or ppp[ord(pc) - a] != wc:
                    # print(www[ord(wc) - a], pc, ppp[ord(pc) - a], wc)
                    return False
            return True
        res = []
        for w in words:
            if valid(w, pattern):
                res.append(w)
        return res
