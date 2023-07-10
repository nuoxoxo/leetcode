class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild)
    {
        if (n == 1)
            return leftChild.size() == 1
                && leftChild[0] == -1
                && rightChild.size() == 1
                && rightChild[0] == -1;

        vector<int> R;
        set<int>    Ls(leftChild.begin(), leftChild.end());
        set<int>    Rs(rightChild.begin(), rightChild.end());
        int     node = -1;

        while (++node < n)
        {
            if (Ls.find(node) == Ls.end()
                && Rs.find(node) == Rs.end()
                && (leftChild[node] ^ -1 || rightChild[node] ^ -1))
                R.push_back(node);
        }
        if (R.size() ^ 1)
            return false;

        int root = R[0];
        set<int>    seen;
        deque<int>  dq = {root};

        while (dq.size())
        {
            int len = (int) dq.size();
            int i = -1;
            while (++i < len)
            {
                node = dq.front();
                dq.pop_front();
                if (node == -1)
                    continue ;
                if (seen.find(node) != seen.end())
                    return false;
                seen.insert(node);
                dq.push_back(leftChild[node]);
                dq.push_back(rightChild[node]);
            }
        }
        return ((int)seen.size() == n);

    }
};
