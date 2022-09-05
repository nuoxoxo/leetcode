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
    vector<vector<int>> levelOrder(Node* root)
    {
        vector<vector<int>> r;
        deque<Node*>        dq;

        if (!root)
            return r;
        dq.push_back(root);
        r.push_back({root->val}); // added
        while (!dq.empty())
        {
            int len = dq.size();
            vector<int> temp;

            while (len--)
            {
                Node *node = dq.front();

                dq.pop_front();
                for (Node *n: node->children)
                {
                    dq.push_back(n);
                    temp.push_back(n->val); // added
                }
            }
            if (!temp.empty())
                r.push_back(temp);
        }
        return r;
    }
};
