class Solution:
    def relativeSortArray(self, arr1: List[int], arr2: List[int]) -> List[int]:
        # D = defaultdict()
        D = {}
        tail = []
        res = []
        for n in arr1:
            if n not in arr2:
                tail.append(n)
        tail.sort()
        for n in arr2:
            D[n] = arr1.count(n)
        # print(D)
        for l, r in D.items():
            res += [l] * r
            print(res)
        return res + tail
