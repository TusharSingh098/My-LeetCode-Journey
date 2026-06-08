class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        
        vector<int> minStk, maxStk;
        minStk.reserve(n);
        maxStk.reserve(n);

        for (int i = 0; i <= n; i++) 
        {
            while (!minStk.empty() && (i == n || nums[minStk.back()] > nums[i])) 
            {
                int poppedIdx = minStk.back();
                minStk.pop_back();
                
                int leftBound = minStk.empty() ? -1 : minStk.back();
                int rightBound = i;
                
                long long subarraysAsMin = 1LL * (poppedIdx - leftBound) * (rightBound - poppedIdx);
                ans -= subarraysAsMin * nums[poppedIdx];
            }
            minStk.push_back(i);
            
            while (!maxStk.empty() && (i == n || nums[maxStk.back()] < nums[i])) 
            {
                int poppedIdx = maxStk.back();
                maxStk.pop_back();
                
                int leftBound = maxStk.empty() ? -1 : maxStk.back();
                int rightBound = i;
                
                long long subarraysAsMax = 1LL * (poppedIdx - leftBound) * (rightBound - poppedIdx);
                ans += subarraysAsMax * nums[poppedIdx];
            }
            maxStk.push_back(i);
        }
        
        return ans;
    }
};