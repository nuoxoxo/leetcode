/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return NULL;
        // assert(node);

        Node * res = new Node(node->val, {});
        deque<Node *> Q{node};

        unordered_map<Node *, Node *> ADJ;        
        ADJ[node] = res;

        while (!Q.empty())
        {
            Node * curr = Q.front();
            Q.pop_front();
            for (Node * neigh: curr->neighbors)
            {
                unordered_map<Node *, Node *>::iterator it = ADJ.find(neigh);
                if (it == ADJ.end())
                {
                    ADJ[neigh] = new Node(neigh->val, {});
                    Q.push_back(neigh);
                }
                ADJ[curr]->neighbors.push_back( ADJ[neigh] );
            }
        }
        return res;
    }
};
