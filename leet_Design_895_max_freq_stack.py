class FreqStack:    
    def __init__(self):
        self.count = {}
        self.group = {}
        self.max = 0

    def push(self, val: int) -> None:
        self.count[val] = 1 + self.count.get(val, 0)
        if self.count[val] > self.max:
            self.max += 1
        if self.count[val] in self.group:
            self.group[self.count[val]].append(val)
        else:
            self.group[self.count[val]] = [val]

    def pop(self) -> int:
        res = self.group[self.max].pop()
        self.count[res] -= 1
        if not self.group[self.max]:
            self.max -= 1
        return res

# Your FreqStack object will be instantiated and called as such:
# obj = FreqStack()
# obj.push(val)
# param_2 = obj.pop()
