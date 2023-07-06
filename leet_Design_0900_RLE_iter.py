class RLEIterator:
    # core = []
    # size = len(core)
    # i = 0

    def __init__(self, encoding: List[int]):
        self.core = encoding
        self.size = len(encoding)
        self.i = 0
        # core = encoding
        # size = len(core)

    def next(self, n: int) -> int:
        while self.i < self.size - 1:
            if n > self.core[self.i]:
                n -= self.core[self.i]
                self.i += 2
            else:
                self.core[self.i] -= n
                return self.core[self.i + 1]
        return -1


# Your RLEIterator object will be instantiated and called as such:
# obj = RLEIterator(encoding)
# param_1 = obj.next(n)
