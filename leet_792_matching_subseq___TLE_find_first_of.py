class Solution:
    def numMatchingSubseq(self, s: str, words: List[str]) -> int:
        def find_first_of(s, c, index):
            for i in range(index, len(s)):
                if c == s[i]:
                    return i
            return -1
        lw = len(words)
        nomatch = []
        for w in words:
            if w in nomatch:
                continue
            i = 0
            for c in w:
                i = find_first_of(s, c, i)
                if (i < 0):
                    lw -= 1
                    nomatch.append(w)
                    break
                i += 1
        return lw
