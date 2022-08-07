class Solution {
public:
    int lastStoneWeight(vector<int>& stones)
    {
        priority_queue<int> p(stones.begin(), stones.end());
        int a, b;

        while (p.size() > 1)
        {
            a = p.top();
            p.pop();
            b = p.top();
            p.pop();
            p.push(a - b);
        }
        return p.top();
    }
};
