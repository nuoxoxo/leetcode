class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        res = []
        for inter in intervals:
            newS, newE = newInterval
            s, e = inter

            # condition #1 - [currInter], [newInter]
            #   ---> just accept the newInter
            if newS > e:
                res.append(inter)

            # condition #2 - [newInter], [currInter]
            #   ---> accept newInter, replace newInter w/ currInter 
            elif newE < s:
                res.append(newInterval)
                newInterval = inter

            # condition #3 - overlapped
            #   ---> update newInter
            #
            #   S--  E  |   S--E    | S  --E
            # s  --e    | s  --  e  |   s--  e
            # 
            elif s <= newE or newS <= e:
                newInterval[0] = min(s, newS)
                newInterval[1] = max(e, newE)
        res.append(newInterval)
        return res

