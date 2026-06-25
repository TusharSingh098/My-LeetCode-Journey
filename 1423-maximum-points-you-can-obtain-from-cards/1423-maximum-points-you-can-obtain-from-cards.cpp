class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size(), curr{0};
        for (int i{0}; i < k; i++) curr += cardPoints[i];

        int maxi{curr};
        for (int i{0}; i < k; i++)
        {
            curr += cardPoints[n - i - 1];
            curr -= cardPoints[k - i - 1];
            maxi = max(maxi, curr);
        }
        return maxi;
    }
};