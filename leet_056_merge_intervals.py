class Solution:
    def merge(self, it: List[List[int]]) -> List[List[int]]:
        size = len(it)
        if size is 0:
            return []
        if size is 1:
            return it
        it.sort()
        res = []
        temp = it[0]
        for n in it:
            if temp[1] >= n[0]:
                temp[1] = max(temp[1], n[1])
            else:
                res.append(temp)
                temp = n
        res.append(temp)
        return res
