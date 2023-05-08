class Solution:
    def stringMatching(self, words: List[str]) -> List[str]:
        r = []
        for sub in words:
            for w in words:
                if w != sub and sub in w:
                    r.append(sub)
                    break
        return r
