class Solution:
    def oddString(self, words: List[str]) -> str:
        assert len(words) > 1
        def reduction(s: str) -> str:
            a = ord('a')
            lowest = 1 + ord('z')
            for c in s:
                lowest = min(lowest, ord(c))
            diff = lowest - a
            return ''.join([chr(ord(_) - diff) for _ in s])
        W = sorted([ (reduction(w), w) for w in words ])
        if W[0][0] == W[1][0]:
            return W[-1][1]
        return W[0][1]
        
