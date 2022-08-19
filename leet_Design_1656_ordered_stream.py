class OrderedStream:
    
    def __init__(self, n: int):
        self.os = [''] * n
        self.I = 0
    def insert(self, idKey: int, value: str) -> List[str]:
        r = []
        self.os[idKey - 1] = value
        # print(self.os)
        for i in range(self.I, len(self.os)):
            # print(self.I, self.os[i])
            if self.os[i] == '':
                return r
            self.I += 1
            r.append(self.os[i])
        return r


# Your OrderedStream object will be instantiated and called as such:
# obj = OrderedStream(n)
# param_1 = obj.insert(idKey,value)
