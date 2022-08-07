class Solution {
public:
    int majorityElement(vector<int>& N)
    {
        int n = N.size();
        if (n == 1)
            return N[0];
        int count = 1;
        int c = 1e9;
        int i = -1;
        while (++i < n)
        {
            if (N[i] == c)
                ++count;
            else
            {
                --count;
                if (!count)
                {
                    c = N[i];
                    count = 1;
                }
            }
        }
        return c ;
    }
};
