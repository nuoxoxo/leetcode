class Solution {
public:
    int minPartitions(string n)
    {
        sort(n.begin(), n.end());
        return n[(int) n.size() - 1] - '0';
    }
};
