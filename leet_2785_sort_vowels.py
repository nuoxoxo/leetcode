class Solution:
    def sortVowels(self, s: str) -> str:
        v = 'aeiouAEIOU'
        vo = []
        for c in s:
            if c in v:
                vo.append(c)
        vo.sort()
        # print(vo)
        i = 0
        res = ''
        for c in s:
            if c not in v:
                res += c
            else:
                res += vo[i]
                i += 1
        return res
        
