class MyHashMap:

    def __init__(self):
        self.keys = []
        self.vals = []

    def put(self, key: int, value: int) -> None:
        if key in self.keys:
            self.vals[ self.keys.index(key) ] = value
            return
        self.vals.append(value)
        self.keys.append(key)

    def get(self, key: int) -> int:
        if key in self.keys:
            return self.vals[ self.keys.index(key) ]
        return -1

    def remove(self, key: int) -> None:
        if key not in self.keys:
            return
        self.vals.pop( self.keys.index(key) )
        self.keys.remove(key)


# Your MyHashMap object will be instantiated and called as such:
# obj = MyHashMap()
# obj.put(key,value)
# param_2 = obj.get(key)
# obj.remove(key)
