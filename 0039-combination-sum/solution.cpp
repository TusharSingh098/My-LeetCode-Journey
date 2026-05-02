class Solution {
public:
    void findCombinations(vector<int>& arr, vector<vector<int>>&ans, vector<int>& ds, int target, int idx) {
        if (idx == arr.size())
        {
            if (target == 0) ans.push_back(ds);
            return;
        }

        if (arr[idx] <= target)
        {
            ds.push_back(arr[idx]);
            findCombinations(arr, ans, ds, target - arr[idx], idx);
            ds.pop_back();
        }

        findCombinations(arr, ans, ds, target, idx + 1);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        findCombinations(candidates, ans, ds, target, 0);
        return ans;
    }

};
