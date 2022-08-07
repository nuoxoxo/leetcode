class MyHashMap:

    def __init__(self):
        self.k = []
        self.v = []

    def put(self, key: int, value: int) -> None:
        if key in self.k:
            self.v[self.k.index(key)] = value
            return
        self.v.append(value)
        self.k.append(key)

    def get(self, key: int) -> int:
        if key in self.k:
            return self.v[self.k.index(key)]
        return -1

    def remove(self, key: int) -> None:
        if key in self.k:
            self.v.pop(self.k.index(key))
            self.k.remove(key)


# Your MyHashMap object will be instantiated and called as such:
# obj = MyHashMap()
# obj.put(key,value)
# param_2 = obj.get(key)
# obj.remove(key)
