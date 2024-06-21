class Solution:
    def maxSatisfied(self, customers: List[int], grumpy: List[int], minutes: int) -> int:
        # cm = 1,0,1,2,1,1,7,5
        #      ^   ^   ^   ^    <--- non-grumpy
        # gm = 0,1,0,1,0,1,0,1
        p1 = 0
        for i, c in enumerate(grumpy):
            if c == 0:
                p1 += customers[i]
                customers[i] = 0
        # sliding window
        p2 = 0
        running = 0
        for i, c in enumerate(customers):
            running += c
            prev = i - minutes
            if prev > -1:
                running -= customers[prev]
            p2 = max(p2, running)
        return p1 + p2

