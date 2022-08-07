class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        plen = len(pattern)
        if plen != s.count(' ') + 1:
            return False
        words = s.split(' ')
        wmap = {}
        pmap = {}
        for i in range(plen):
            p = pattern[i]
            w = words[i]
            if p not in pmap and w not in wmap:
                pmap[p] = w
                wmap[w] = p
            elif (p in pmap and pmap[p] != w) or (w in wmap and wmap[w] != p):
                return False
        return True
