class Solution:
    def buildArray(self, target: List[int], n: int) -> List[str]:
        res = []
        cur = 0
        for i in range(1, n + 1):
            if cur == len(target):
                break
            if target[cur] == i:
                cur += 1
                res.append('Push')
            else:
                res.append('Push')
                res.append('Pop')
        return res
