class Solution {
public:
    int maximumGain(string s, int x, int y)
    {
        // cdbcbbaaabab
        //         ^^^^
        //     ^^^^
        // aabbaaxybbaabb -> should be 20 pts
        // ^^^^           -> ab * 2 = 5x2 = 10
        //           ^^^^ -> ab * 2 = 5x2 = 10
        string t;
        for (char c : s)
        {
            if (c == 'a') t += 'b';
            else if (c == 'b') t += 'a';
            else t += c;
        }
        return max(f(s, x, y), f(t, y, x));
    }

    static int f(string s, int x, int y)
    {
        int res = 0;
        deque<char> Q;
        // hint from subj:
        // it is always more optimal to take one type of substring before another
        // -> handle ab
        for (char c : s)
        {
            Q.push_back(c);
            while (Q.size() > 1 && Q[Q.size() - 2] == 'a' && Q[Q.size() - 1] == 'b')
            {
                res += x;
                Q.pop_back();
                Q.pop_back();
            }
        }
        int i = 0;
        deque<char> R;
        for (auto c : Q)
        {
            R.push_back(c);
            while (R.size() > 1 && R[R.size() - 2] == 'b' && R[R.size() - 1] == 'a')
            {
                res += y;
                R.pop_back();
                R.pop_back();
            }
        }
        return res;
    }
};
