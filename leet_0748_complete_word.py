class Solution:
    def shortestCompletingWord(self, licensePlate: str, words: List[str]) -> str:
        D = defaultdict(int)
        for c in licensePlate:
            if c.isalpha():
                D[c.lower()] += 1
        res = ''
        for word in words:
            d = D.copy()
            for c in word:
                if c.isalpha():
                    d[c.lower()] -= 1
            ok = True
            for n in d.values():
                if n > 0:
                    ok = False
                    break
            if ok:
                if res == '' or len(word) < len(res):
                    res = word
        return res
