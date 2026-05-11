class Solution {
private:
    void merge(vector<int>& arr, int low, int mid, int high, vector<int>& temp, int& count)
    {
        int left{low}, right{mid + 1};

        while (left <= mid && right <= high)
        {
            if (arr[left] > 2LL * arr[right])
            {
                count += mid - left + 1;
                right++;
            }
            else left++;
        }

        left = low; right = mid + 1;
        int k = low;
        while (left <= mid && right <= high) 
        {
            if (arr[left] <= arr[right]) temp[k++] = arr[left++];
            else temp[k++] = arr[right++];
        }

        while (left <= mid) temp[k++] = arr[left++];
        while (right <= high) temp[k++] = arr[right++];

        for (int i = low; i <= high; i++) arr[i] = temp[i];
    }
    
    void divide(vector<int>& arr, int low, int high, vector<int>& temp, int& count)
    {
        if (low >= high) return;

        int mid{low + (high - low) / 2};

        divide(arr, low, mid, temp, count);
        divide(arr, mid + 1, high, temp, count);

        merge(arr, low, mid, high, temp, count);
    }

public:
    int reversePairs(vector<int>& nums) {
        int count{0};
        vector<int> temp(nums.size());
        divide(nums, 0, (int)nums.size() - 1, temp, count);
        return count;
    }
};
