class Solution {
public:
    bool winnerOfGame(string colors)
    {
        if ((int) colors.length() < 3)
            return false;
        int a = 0;
        int b = 0;
        int i = 0;
        while (++i < (int) colors.length() - 1)
        {
            if (colors[i - 1] == colors[i] && colors[i] == colors[i + 1])
            {
                if (colors[i] == 'A')
                    ++a;
                else
                    ++b;
            }
        }
        return a > b;
    }
};
