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

class Solution {
public:
    vector<int> preorder(Node* root)
    {
        vector<int> E;
        helper(root, E);
        return E ;
    }

    void    helper(Node* p, vector<int>& v)
    {
        if (!p)
		return ;

        int i = -1;
        v.push_back(p->val) ;
        while (++i < p->children.size())
		helper(p->children[i], v);
    }
};
