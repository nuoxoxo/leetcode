class LRUCache:

    # helper Node class
    class Node:
        # constr
        def __init__(self, key, val):
            self.key = key
            self.val = val
            self.prev = None
            self.next = None

    def __init__(self, capacity: int):

        # 2 global trackers
        self.Dict = {}
        self.Cap = capacity

        # circular linked list
        # init to head->tail->head

        #   head node
        self.head = self.Node(0, 0)
        self.tail = self.Node(0, 0)

        #   tail node
        self.head.next = self.tail
        self.tail.prev = self.head

    # remove
    def remove(self, node):
        self.Dict.pop(node.key)
        node.next.prev = node.prev
        node.prev.next = node.next

    # insert
    def insert(self, node):
        node.next = self.head.next
        self.head.next.prev = node
        self.head.next = node
        node.prev = self.head
        self.Dict[node.key] = node

    def get(self, key: int) -> int:
        if key not in self.Dict:
            return -1
        node = self.Dict[key]
        self.remove(node)
        self.insert(node)
        return node.val

    def put(self, key: int, value: int) -> None:
        if key in self.Dict:
            self.remove(self.Dict[key])
        if len(self.Dict) == self.Cap:
            self.remove(self.tail.prev)
        self.insert(self.Node(key, value))


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)

