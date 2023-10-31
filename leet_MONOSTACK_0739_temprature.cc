class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures)
    {
        vector<int> res(temperatures.size(), 0);
        stack<int>  hot;
        int         i;
        
        i = temperatures.size();
        while (--i > -1)
        {
            while (!hot.empty() && (temperatures[i] >= temperatures[hot.top()]))
                hot.pop();
            if (!hot.empty())   res[i] = hot.top() - i;
            hot.push(i);
        }
        return (res);
    }
};

/*

/// brute forcing gets you TLE

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures)
    {
        vector<int> answer;
        int         i, j;

        i = -1;
        while (++i < temperatures.size() - 1)
        {
            j = i;
            while (++j < temperatures.size())
            {
                if (temperatures[j] > temperatures[i])
                {
                    answer.push_back(j - i);
                    break;
                }
            }
            if (answer.size() != i + 1) answer.push_back(0);
        }
        answer.push_back(0);
        return (answer);
    }
};

*/
