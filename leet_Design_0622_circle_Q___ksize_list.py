class MyCircularQueue:

    def __init__(self, k: int):
        self.dq = [None] * k
        self.curr = 0
        self.size = 0
        self.K = k


    def enQueue(self, value: int) -> bool:
        if self.isFull():
            return False
        self.dq[(self.curr + self.size) % self.K] = value
        self.size += 1
        return True

    def deQueue(self) -> bool:
        if self.isEmpty():
            return False
        self.curr = (self.curr + 1) % self.K
        self.size -= 1
        return True

    def Front(self) -> int:
        if self.isEmpty():
            return -1
        return self.dq[self.curr]

    def Rear(self) -> int:
        if self.isEmpty():
            return -1
        dest = self.curr + self.size - 1
        return self.dq[dest % self.K]

    def isEmpty(self) -> bool:
        return self.size == 0

    def isFull(self) -> bool:
        return self.size == self.K


# Your MyCircularQueue object will be instantiated and called as such:
# obj = MyCircularQueue(k)
# param_1 = obj.enQueue(value)
# param_2 = obj.deQueue()
# param_3 = obj.Front()
# param_4 = obj.Rear()
# param_5 = obj.isEmpty()
# param_6 = obj.isFull()
