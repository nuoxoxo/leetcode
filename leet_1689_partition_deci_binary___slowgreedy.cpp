class Solution {
public:
    int minPartitions(string s)
    {
        int res = 0;
        while (s.length())
        {
            string  temp = "";

            for (char c: s)
            {
                if (temp != "" || c - 1 > '0')
                    temp += c - 1;
            }
            swap(s, temp);
            ++res;
        }
        return res;
    }
};
