class Solution:
    def truncateSentence(self, s: str, k: int) -> str:
        r = s.split(' ')[:k]
        s = ' '.join(r)
        return s
    # sls :: str to lst to str
