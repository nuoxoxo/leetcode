/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, List<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    public List<List<Integer>> levelOrder(Node root) {
        List<List<Integer>> r = new LinkedList<>();
        LinkedList<Node>    dq = new LinkedList<>();

        if (root == null)
            return r;
        dq.add(root);
        while (! dq.isEmpty())
        {
            LinkedList<Integer> temp = new LinkedList<>();
            int                 len = dq.size();

            while (len-- > 0)
            {
                System.out.println(len);
                Node    node = dq.pollFirst();

                for (Node n: node.children)
                    dq.addLast(n);
                temp.add(node.val);
            }
            r.add(temp);
        }
        return r;
    }
}
