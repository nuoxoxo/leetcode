class Solution:
    def smallestChair(self, times: List[List[int]], targetFriend: int) -> int:

        # idea/ - two min heaps
        #   --> 1st heap keeps chairs now available
        #   --> 2nd heap keeps runnning events

        N = len(times)
        chairs = []
        for i in range(N):
            heapq.heappush(chairs, i)

        events = []
        staying, hasleft = 1, 0 # 2 states
        for i, (arrive, _) in enumerate(times): # <--- we dont care abt departure time
            heapq.heappush(events, (arrive, staying, i))

        # main soln
        while True:
            arrive, state, idx = heapq.heappop(events)
            if state == hasleft:
                heapq.heappush(chairs, idx)
            else:
                chair = heapq.heappop(chairs)
                if idx == targetFriend:
                    return chair
                leavingtime = times[idx][1] # <--- track leaving by pushing timestamp of leaving
                heapq.heappush(events, ( leavingtime, hasleft, chair))
        assert False

        # dont know what goes wrong
        """
        t = [ [i + 1, _[0], _[1]] for i, _ in enumerate(times) ]
        t.sort(key=lambda x: x[1])
        while True:
            # print("bef/", t)
            todos = []
            for i, line in enumerate(t):
                _, arr, cnt = line
                if arr < 2 and cnt == 0:
                    todos.append(i)
            for i in range(len(todos) - 1, -1, -1):
                del t[todos[i]]
            # print("aft/", t)
            for i, friend in enumerate(t):
                idx, arr, _ = friend
                if idx == targetFriend + 1 and arr == 1:
                    # print("res/", t, '\n')
                    return i
                if arr < 2:
                    t[i][2] -= 1
                else:
                    t[i][1] -= 1
        assert False
        """
