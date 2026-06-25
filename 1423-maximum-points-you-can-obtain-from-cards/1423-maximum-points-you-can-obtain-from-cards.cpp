class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int total{0}, curr{0};
        for (int i{0}; i < n; i++)
        {
            if (i < n - k) curr += cardPoints[i];
            total += cardPoints[i];
        }

        int left{0}, ans{0};
        ans = max(ans, total - curr);
        for (int right{n - k}; right < n; right++)
        {
            curr += cardPoints[right];
            curr -= cardPoints[left++];
            ans = max(ans, total - curr);
        }
        return ans;
    }
};