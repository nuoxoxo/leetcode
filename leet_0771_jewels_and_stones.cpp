class Solution {
public:
    int numJewelsInStones(string jewels, string stones)
    {
        int res = 0;

        for (char c : stones)
        {
            for (char j : jewels )
                if (c == j)
                    res++;
        }
        return res;
    }
};
