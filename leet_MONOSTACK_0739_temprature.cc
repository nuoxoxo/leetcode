class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& TP)
    {
        vector< vector<int>(*)(vector<int>&) > Solutions {
            Monotonic_stack_backward,
            // Monotonic_stack_forward,
            // Bruteforce_TLE,
        };
        return Solutions[ std::rand() % Solutions.size() ](TP);
    }

    static vector<int> Monotonic_stack_forward(vector<int> & t)
    {
        vector<int> res( t.size(), 0 );
        deque<int>  dq;
        int i = -1;
        while (++i < t.size())
        {
            while ( !dq.empty() && t[dq.back()] < t[i] ) // '<' used if backward
            {
                res[ dq.back() ] = i - dq.back();
                dq.pop_back();
            }
            dq.push_back( i );
        }
        return res;
    }

    static vector<int> Monotonic_stack_backward(vector<int> & t)
    {
        vector<int> res( t.size(), 0 );
        std::deque<int> dq;
        int i = t.size();
        while (--i > -1)
        {
            while ( !dq.empty() && t[dq.back()] <= t[i] ) // '<=' : necessary if backward
                dq.pop_back();
            if ( !dq.empty() )
                res[i] = dq.back() - i;
            dq.push_back(i);
        }
        return res;
    }

    static vector<int> Bruteforce_TLE(vector<int> & t)
    {
        int len = (int) t.size();
        vector<int> res( len, 0 );
        int i = -1;
        while (++i < len - 1)
        {
            int j = i;
            while (++j < len)
            {
                if (t[i] < t[j])
                {
                    res[i] = j - i;
                    break ;
                }
            }
        }
        return res;
    }

};
