class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations)
    {
        int     x = 0;

        for (string s : operations)
        {
            for (char c : s)
            {
                if (c == '+')
                {
                    ++x;
                    break ;
                }
                if (c == '-')
                {
                    --x;
                    break ;
                }
            }
        }
        return x;
    }
};
