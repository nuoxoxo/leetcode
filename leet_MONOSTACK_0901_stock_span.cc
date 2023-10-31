class StockSpanner {

//  added a private attr
vector<pair<int, int>>  _dq;

public:
    StockSpanner() {}
    
    int next(int price)
    {
        int p = price;
        int res = 1;
        while (_dq.size() && _dq.back().first <= p)
        {
            pair<int, int>  item = _dq.back();
            int prev_price = item.first;
            int prev_res = item.second;
            res += prev_res;
            _dq.pop_back();
        }
        _dq.push_back( {p, res} );
        return res;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
