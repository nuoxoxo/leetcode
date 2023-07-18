class Node {

    public key: number
    public val: number
    public prev: Node | null
    public next: Node | null

    constructor( key: number, val: number) {

        this.key = key
        this.val = val
        this.prev = null
        this.next = null
    }
}


class LRUCache {

    private head: Node
    private tail: Node
    private Cap: number
    private Dict: {
        [key: number]: Node
    }

    constructor(capacity: number) {

        this.Cap = capacity
        this.head = new Node(0, 0)
        this.tail = new Node(0, 0)
        this.head.next = this.tail
        this.tail.prev = this.head
        this.Dict = {}
    }

    private remove(node: Node) {

        delete this.Dict[node.key]

        if ( node.prev ) {
            node.prev.next = node.next
        }
        if ( node.next ) {
            node.next.prev = node.prev
        }
    }

    private insert(node: Node) {

        node.next = this.head.next
        this.head.next!.prev = node
        this.head.next = node
        node.prev = this.head

        this.Dict[node.key] = node
    }

    get(key: number): number {

        if ( !(key in this.Dict) ) {
            return -1
        }
        const node = this.Dict[key];
        this.remove(node)
        this.insert(node)

        return node.val
    }

    put(key: number, value: number): void {

        if (key in this.Dict) {
            this.remove(this.Dict[key])
        }
        if (Object.keys(this.Dict).length === this.Cap) {
            this.remove(this.tail.prev!)
        }
        this.insert(new Node(key, value))
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * var obj = new LRUCache(capacity)
 * var param_1 = obj.get(key)
 * obj.put(key,value)
 */
