class Solution:
    def findRepeatedDnaSequences(self, s: str) -> List[str]:
        n = len(s)
        if n < 10:
            return []
        r, seen = set(), set()
        for i in range(n - 9):
            temp = s[i: i + 10]
            if temp in seen:
                r.add(temp)
            seen.add(temp)
        return list(r)
