class Solution:
    def countAsterisks(self, s: str) -> int:
        a = s.split('|')
        print(a)
        r = 0
        for i in range(0, len(a), 2):
            r += a[i].count('*')
        return r
