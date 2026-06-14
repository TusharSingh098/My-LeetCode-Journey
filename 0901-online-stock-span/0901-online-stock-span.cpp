class StockSpanner 
{
private:
    std::vector<int> prices;
public:
    StockSpanner() {}
    
    int next(int price) 
    {
        prices.push_back(price);
        int i = prices.size() - 1, count{0};
        while (i >= 0 && prices[i] <= price)
        {
            count++;
            i--;
        }
        return count;
    }
};