class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        last_index = {}
        res = []
        ls = len(s)
        for i in range(ls):
            last_index[s[i]] = i
        i = 0
        while i < ls:
            last = last_index[s[i]]
            if last == ls - 1:
                res.append(ls - i)
                return res
            j = i
            while j < last:
                temp = last_index[s[j]]
                last = max(last, temp)
                j += 1
            res.append(1 + j - i)
            i = j + 1
        return res
