class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power)
    {
        int         i, j, cur, res;

        sort(tokens.begin(), tokens.end());
        i = 0;
        j = tokens.size() - 1;
        res = cur = 0;
        while (i <= j)
        {
            if (tokens[i] <= power) // Greedy: if gain is possible, make the gain
            {
                cur += 1;
                res = max(res, cur);
                power -= tokens[i];
                i++;
            }
            else if (cur > 0)
            {
                cur -= 1;
                power += tokens[j];
                j -= 1;
            }
            else
            {
                break ;
            }
        }
        return res;
    }
};
