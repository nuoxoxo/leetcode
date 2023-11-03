class Solution:
    def findContentChildren(self, g: List[int], s: List[int]) -> int:
        gg, ss = 0, 0
        g.sort()
        s.sort()
        while gg < len(g) and ss < len(s):
            if g[gg] <= s[ss]:
                gg += 1
            ss += 1
        return gg
        
