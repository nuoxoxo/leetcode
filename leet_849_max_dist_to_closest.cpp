class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int     i, j, size, tmpd, maxd;
        bool    end;

        i = -1;
        maxd = 1;
        end = false;
        size = seats.size();
        while (++i < size)
        {
            if (maxd > size / 2)
                break ;
            if (!seats[i])
            {
                j = i;
                while (j < size && !seats[j])
                {
                    j++;
                    if (j == size)
                        end = true;
                }
                if (end || !i)
                    tmpd = j - i;
                else
                    tmpd = (j - i) / 2;
                if ((j - i) % 2 && !end && i)
                    tmpd += 1;
                if (tmpd > maxd)
                    maxd = tmpd;
                if (end)
                    break ;
                i = j;
            }
            // i++;
        }
        return maxd ;
    }
};
