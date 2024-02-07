class Solution:
    def frequencySort(self, s: str) -> str:
        return [
            self.Oneliner,
            self.Pre_oneliner,
        ][ 1 ]( s )

    def Oneliner(self, s: str) -> str:
        return ''.join([ c * fq for c, fq in dict(sorted(Counter(s).items(), key=lambda x: (x[1], x[0]), reverse=True)).items()])

    def Pre_oneliner(self, s: str) -> str:
        res = ''
        for k,v in dict(sorted(Counter(s).items(), key=lambda x: (x[1], x[0]), reverse=True)).items():
            for _ in range(v):
                res += k
        return res
