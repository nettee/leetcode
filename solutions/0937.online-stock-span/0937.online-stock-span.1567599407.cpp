class StockSpanner {
public:
    StockSpanner() {
        // do nothing
    }
    
    int next(int price) {
        int count = 1;
        while (!s.empty() && s.top().first <= price) {
            count += s.top().second;
            s.pop();
        }
        s.push(make_pair(price, count));
        return count;
    }
    
private:
    // (price, count)
    stack<pair<int, int>> s;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
