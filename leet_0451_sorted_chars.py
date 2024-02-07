class Solution:
    def frequencySort(self, s: str) -> str:
        res = ''
        for k,v in dict(sorted(Counter(s).items(), key=lambda x: (x[1], x[0]), reverse=True)).items():
            for _ in range(v):
                res += k
        return res
