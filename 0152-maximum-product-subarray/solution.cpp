class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];

        int preProduct{1}, firstN{0};
        int maxProduct{nums[0]};

        for (int num: nums)
        {
            preProduct *= num;
            maxProduct = max(maxProduct, preProduct);

            if (preProduct < 0)
            {
                if (firstN != 0) maxProduct = max(maxProduct, preProduct / firstN);
                else firstN = preProduct;                
            }
            else if (preProduct == 0)
            {
                preProduct = 1;
                firstN = 0;
            }
        }
        return maxProduct;
    }
};
