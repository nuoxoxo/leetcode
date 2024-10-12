class Solution:
    def minGroups(self, intervals: List[List[int]]) -> int:
        # [5,10],[6,8],[1,5],[2,3],[1,10]
        # 1 _ _ _ 5
        #         5 _ _ _ _ 10
        # 1 _ _ _ _ _ _ _ _ 10
        #           6 _ 8
        #   2 3

        res = []
        intervals.sort()
        for L, R in intervals:
            if not res:
                heapq.heappush(res, R)
                continue
            l = res[0]
            if l < L:
                heapq.heappop(res)
            heapq.heappush(res, R)
        return len(res)

        """

        # initial solnm

        res = []
        heap = intervals
        # print(heapq.nsmallest(len(heap), heap))
        while intervals:
            # print(res)
            l, r = heapq.heappop(intervals)
            found = False
            # print('up/', res, l, r)
            if not res:
                res.append([l, r])
                continue
            for i, gp in enumerate(res):
                L, R = gp
                if l <= L and r <= L:
                    res[i] = [l, L]
                if R <= l and R <= r:
                    res[i] = [R, l]
                    found = True
                    break
            if not found: res.append([l, r])
            # print('down/', res, l, r)
        print(res)
        return len(res)
        """

