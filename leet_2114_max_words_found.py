class Solution:
    def mostWordsFound(self, sentences: List[str]) -> int:
        res = -1
        for s in sentences:
            sp = s.count(' ') + 1
            if res < sp:
                res = sp
        return res
