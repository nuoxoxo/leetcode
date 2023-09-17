class Solution:
    def minimumEffortPath(self, heights: List[List[int]]) -> int:
        R = len(heights)
        C = len(heights[0])
        dq = [
            [0, 0, 0]
        ]
        seen = set()
        dirs = [
            [0, 1], [0, -1], [1, 0], [-1, 0]
        ]

        while dq:
            eff, r, c = heapq.heappop(dq)
            if (r, c) in seen:
                continue
            seen.add((r, c))
            if r == R - 1 and c == C - 1:
                return eff
            for dr, dc in dirs:
                rr, cc = r + dr, c + dc
                if rr < 0 or rr == R or cc < 0 or cc == C \
                    or (rr, cc) in seen:
                    continue
                temp = max(eff, abs(heights[r][c] - heights[rr][cc]))
                heapq.heappush(dq, [temp, rr, cc])

