class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a /*asteroids*/)
    {
        vector<int> D;
        int i = 0;
        while (i < (int) a.size())
        {
            // ( -, + ) <queue[-1], incoming>
            // ---> No collision bc they part ways ( << , >> )
            if (D.empty() || a[i] > -1 || D.back() < 0)
            {
                D.push_back(a[i]);
                ++i;
            }
            // ( + , - )<queue[-1], incoming>
            // ---> Is the only possoble colliding scenario
            else if (D.back() + a[i] == 0)
            {
                // either they cancel each other
                D.pop_back();
                ++i;
            }
            else if (D.back() + a[i] < 0)
            {
                // or queue[-1] gets eaten
                D.pop_back();
            }
            else
            {
                ++i;
            }
        }
        return D;
    }
};
