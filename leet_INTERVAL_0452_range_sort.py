class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        return [
            ### Greedy end sorting
            self.Logic_Two_update_running_end,
            # self.Logic_One_update_both_ends,
        ][ 0 ]( points )

    def Logic_One_update_both_ends(self, points: List[List[int]]) -> int:
        # |          .     .
        # |       .    .
        # |  .     .
        # | .    .
        #   ---> range sort
        points.sort()
        s, e = points[0] # point of reference
        res = 1
        for i in range(1, len(points)):
            newS, newE = points[i]
            if newS <= e:
                # -----x    running end
                #   x-----  new start
                # TODO - two ways
                #   1) shrink range - 2) update Running End only
                s = max(s, newS)
                e = min(e, newE)
            else:
                # (Possibility : newS > running end)
                # --x       running end
                #     x--   new start
                # TODO - two ways 
                #   1) update the range - 2) update Running End
                res += 1
                e = newE
                s, e = newS, newE
        return res

    def Logic_Two_update_running_end(self, points: List[List[int]]) -> int:
        points.sort()
        _, runningE = points[0]
        res = 1
        for i in range(1, len(points)):
            newS, newE = points[i]
            if newS <= runningE: # overlapped
                runningE = min(newE, runningE)
            else: # start a new active set
                res += 1
                runningE = newE
        return res

