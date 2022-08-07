class Solution:
    def numSubmatrixSumTarget(self, grid: List[List[int]], target: int) -> int:
        def subarray_sum(arr: List[List[int]], target: int) -> int:
            # D = defaultdict()     # usual mistake
            D = defaultdict(lambda: 0)
            size = len(arr)
            tt = 0
            res = 0
            for i in range(size):
                tt += arr[i]
                if tt == target:
                    res += 1
                res += D[tt - target]
                D[tt] += 1;
            return res
        r = len(grid)
        if r == 0:
            return 0
        c = len(grid[0])
        count = 0
        for i in range(r):
            temp = [0] * c
            for j in range(i, -1, -1):
                for k in range(c):
                    temp[k] += grid[j][k]
                count += subarray_sum(temp, target)
        return count
