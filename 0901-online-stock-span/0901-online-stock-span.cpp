class StockSpanner 
{
private:
    std::stack<std::pair<int, int>> stk;
public:
    StockSpanner() {}
    
    int next(int price) 
    {
        int count{1};

        while (!stk.empty() && stk.top().first <= price) 
        {
            count += stk.top().second;
            stk.pop();
        }
        
        stk.push({price, count});
        return count;
    }
};