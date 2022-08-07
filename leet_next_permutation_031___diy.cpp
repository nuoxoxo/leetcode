class Solution {
public:
    void nextPermutation(vector<int>& n)
    {
        int len = (int) n.size();
        int index = -1;
        int i = len;
        while (--i)
        {
            if (n[i - 1] < n[i])
            {
                index = i;
                break;
            }
        }
        if (index != -1)
        {
            int prev = index;
            while (++i < len)
                if(n[i] > n[index - 1] && n[i] <= n[prev])
                    prev = i;
            swap(n[index - 1], n[prev]);
            reverse(n.begin() + index, n.end());
        }
        else
            reverse(n.begin(), n.end());
    }
};
