class Solution {
public:
    int countKthRoots(int l, int r, int k) {
        if (k == 1) return r - l + 1;
        int start = ceil(pow(l, 1.0 / k) - 1e-9);
        int end = floor(pow(r, 1.0 / k) + 1e-9);
        return start > end ? 0 : end - start + 1;
    }
};
