class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();

        std::unordered_set<int> uniques;
        uniques.reserve(nums.size()); 
        uniques.insert(nums.begin(), nums.end());
        
        int longest{0};
        for (const int& num: uniques)
        {
            if (uniques.find(num - 1) == uniques.end())
            {
                int i{1};
                while (uniques.find(num + i) != uniques.end()) i++;
                longest = std::max(longest, i);
            }
        }
        return longest;
    }
};
