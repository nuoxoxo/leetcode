class Solution {
public:
    int maxDepth(Node* node)
    {
        if (!node)
            return 0;
        int res = 0;
        for (Node* n: node->children)
            res = max(res, maxDepth(n));
        return res + 1;
    }
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
