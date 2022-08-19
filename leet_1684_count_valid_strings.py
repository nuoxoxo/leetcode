class Solution:
    def countConsistentStrings(self, allowed: str, words: List[str]) -> int:
        r = 0
        for w in words:
            ok = True
            for c in w:
                if c not in allowed:
                    ok = False
                    break
            if ok:
                r += 1
        return r
