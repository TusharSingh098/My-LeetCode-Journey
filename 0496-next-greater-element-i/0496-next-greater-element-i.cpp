class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
    {
        stack<int> stk;
        unordered_map<int, int> mpp;

        for (int i = nums2.size() - 1; i >= 0; i--)
        {
            int num = nums2[i];
            while (!stk.empty() && num > stk.top()) stk.pop();

            if (stk.empty()) mpp[num] = -1;
            else mpp[num] = stk.top();
            stk.push(num);
        }
        vector<int> ans;
        for (int num: nums1) ans.push_back(mpp[num]);
        return ans;
    }
};