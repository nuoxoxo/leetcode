class MyQueue:

    def __init__(self):
        self.D = []

    def push(self, x: int) -> None:
        self.D.append(x)

    def pop(self) -> int:
        return self.D.pop(0) if self.D else 1e9

    def peek(self) -> int:
        return self.D[0]

    def empty(self) -> bool:
        return not self.D

# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()
