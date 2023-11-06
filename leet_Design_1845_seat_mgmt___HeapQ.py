class SeatManager:

    def __init__(self, n: int):
        self.prev = 0
        self.heap = []

    def reserve(self) -> int:
        if self.heap:
            return heapq.heappop(self.heap)
        self.prev += 1
        return self.prev

    def unreserve(self, seatNumber: int) -> None:
        if seatNumber == self.prev:
            self.prev -= 1
        else:
            heapq.heappush(self.heap, seatNumber)


# Your SeatManager object will be instantiated and called as such:
# obj = SeatManager(n)
# param_1 = obj.reserve()
# obj.unreserve(seatNumber)
