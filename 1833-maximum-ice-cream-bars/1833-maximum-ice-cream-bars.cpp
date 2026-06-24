class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int maxi{0};
        for (int cost: costs) maxi = max(maxi, cost);
        maxi += 1;

        vector<int> values(maxi, 0);
        
        for (int cost: costs) values[cost]++;

        int count{0};

        for (int i{1}; i < maxi; i++)
        {
            if (values[i] == 0) continue;

            if (coins < i) break;

            int buy = min(values[i], coins / i);
            
            coins -= buy * i;
            count += buy;
        }
        return count;
    }
};
