class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<double> merged(n1 + n2);
        int i{0}, j{0}, k{0};

        while (i < n1 && j < n2)
        {
            if (nums1[i] <= nums2[j])
            {
                merged[k] = nums1[i];
                i++;
            }
            else
            {
                merged[k] = nums2[j];
                j++;
            }
            k++;
        }
        while (i < n1)
        {
            merged[k] = nums1[i];
            i++;
            k++;
        }
        while (j < n2)
        {
            merged[k] = nums2[j];
            j++;
            k++;
        }
        if ((n1 + n2) % 2 == 0) return (merged[((n1 + n2) / 2) - 1] + merged[(n1 + n2) / 2]) / 2;
        else return merged[(n1 + n2) / 2];
    }
};
