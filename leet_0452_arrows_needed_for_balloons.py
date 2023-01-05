class Solution:
    def findMinArrowShots(self, pts: List[List[int]]) -> int:
        
        # up_front, up_end, down_front, down_end
        
        pts.sort()
        L = len(pts)
        uf, ue = pts[0][0], pts[0][1]
        i = 0
        count = 1
        while i < L - 1:
            i += 1
            df, de = pts[i][0], pts[i][1]
            if df <= ue:
                uf, ue = max(uf, df), min(ue, de)
            else:
                count += 1
                uf, ue = df, de
        
        return count
