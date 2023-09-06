/**
 * Definition for Node.
 * class Node {
 *     val: number
 *     next: Node | null
 *     random: Node | null
 *     constructor(val?: number, next?: Node, random?: Node) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.next = (next===undefined ? null : next)
 *         this.random = (random===undefined ? null : random)
 *     }
 * }
 */

function copyRandomList(head: Node | null): Node | null {
    const E: Map<Node | null, Node | null> = new Map();

    let curr: Node | null = head;

    while (curr !== null) {
        const temp: Node | null = new Node(curr.val);
        E.set(curr, temp);
        curr = curr.next;
    }

    curr = head;

    while (curr !== null) {
        const ptr: Node | null = E.get(curr);
        if (ptr !== undefined) {
            ptr.next = E.get(curr.next) || null;
            ptr.random = E.get(curr.random) || null;
        }
        curr = curr.next;
    }

    return E.get(head) || null;
};
