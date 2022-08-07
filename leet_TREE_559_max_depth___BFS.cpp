class Solution {
public:
    int maxDepth(Node* node)
    {
        if (!node)
            return 0;
        int             res = 0;
        deque<Node*>    dq;

        dq.push_back(node);
        res = 0;
        while (!dq.empty())
        {
            ++res;
            int len = (int) dq.size();
            while (len --)
            {
                Node    *p = dq.front();
                dq.pop_front();
                for (Node *n: p->children)
                    if (n)
                        dq.push_back(n);
            }
        }
        return res ;
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


