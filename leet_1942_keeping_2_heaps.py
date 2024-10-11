class Solution:
    def smallestChair(self, times: List[List[int]], targetFriend: int) -> int:

        # idea/ - two min heaps
        #   --> 1st heap keeps chairs now available
        #   --> 2nd heap keeps runnning events
        #   (
        #       arrival_time,
        #       is_present, ---> will be int for heapQ sorting
        #       idx, ---> i-th friend
        #   )

        N = len(times)
        chairs = []
        for i in range(N):
            heapq.heappush(chairs, i)

        events = []
        willstay, hasleft = 1, 0 # 2 states
        for idx, (arrive, _) in enumerate(times): # <--- we dont care abt departure time
            heapq.heappush(events, (arrive, willstay, idx))

        print(heapq.nsmallest(len(events), events)) # <--- here's how to print heapQ
        # [[1,4],[2,3],[4,6]]
        # ---heapified events---> [(1, 1, 0), (2, 1, 1), (4, 1, 2)]

        # [[3,10],[1,5],[2,6]]
        # ---heapified events---> [(1, 1, 1), (2, 1, 2), (3, 1, 0)]

        # soln
        while True:
            arrive, state, friend = heapq.heappop(events)
            if state == hasleft:
                heapq.heappush(chairs, friend)
            else:
                chair_to_free = heapq.heappop(chairs)
                if friend == targetFriend:
                    return chair_to_free
                leavingtime = times[friend][1] # <--- track leaving by pushing timestamp of leaving
                heapq.heappush(events, ( leavingtime, hasleft, chair_to_free))
        assert False

