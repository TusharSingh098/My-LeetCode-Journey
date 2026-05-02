class Solution {
public:
    void findCombinations(vector<int>& arr, vector<vector<int>>& ans, vector<int>& ds, int target, int idx)
    {
        if (target == 0)
        {
            ans.emplace_back(ds);
            return;
        }
        for (int i{idx}; i < arr.size(); i++)
        {
            if (i > idx && arr[i] == arr[i - 1]) continue;
            if (arr[i] > target) break;
            ds.push_back(arr[i]);
            findCombinations(arr, ans, ds, target - arr[i], i + 1);
            ds.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> ds;
        findCombinations(candidates, ans, ds, target, 0);
        return ans;
    }
};
