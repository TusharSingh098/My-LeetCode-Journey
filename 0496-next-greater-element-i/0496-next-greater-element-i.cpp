class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
    {
        unordered_map<int, int> mpp;
        stack<int> stk;

        for (int num: nums2)
        {
            while (!stk.empty() && num > stk.top())
            {
                mpp[stk.top()] = num;
                stk.pop();
            }
            stk.push(num);
        }
        while (!stk.empty())
        {
            mpp[stk.top()] = -1;
            stk.pop();
        }
        vector<int> ans;
        for (int num: nums1)
        {
            ans.push_back(mpp[num]);
        }
        return ans;
    }
};