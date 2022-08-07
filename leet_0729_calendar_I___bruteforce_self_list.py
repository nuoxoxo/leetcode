class MyCalendar:

    def __init__(self):
        self.mp = []

    def book(self, start: int, end: int) -> bool:
        for p in self.mp:
            if not (p[0] > end - 1 or p[1] < start):
                return False
        self.mp.append([start, end - 1])
        return True


# Your MyCalendar object will be instantiated and called as such:
# obj = MyCalendar()
# param_1 = obj.book(start,end)
