class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        
        vector<int> costEven(k, 0), costOdd(k, 0);
        
        for (int target = 0; target < k; target++) {
            
            for (int i = 0; i < n; i += 2) 
            {
                int rem = nums[i] % k;
                int dist{min(abs(rem - target), k - abs(rem - target))};
                costEven[target] += dist;
            }
            
            for (int i = 1; i < n; i += 2) 
            {
                int rem = nums[i] % k;
                int dist{min(abs(rem - target), k - abs(rem - target))};
                costOdd[target] += dist;
            }
        }
        
        int minOps{INT_MAX};
        
        for (int x = 0; x < k; x++) 
        {
            for (int y = 0; y < k; y++) 
            {
                if (x == y) continue;
                
                int current_cost = costEven[x] + costOdd[y];
                minOps = min(minOps, current_cost);
            }
        }
        
        return minOps;
    }
};
