class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](const vector<int>& a, const vector<int>& b) {return a[1] > b[1];});

        int totalUnits = 0;

        for (const auto& box: boxTypes) {
            if (truckSize == 0) break;

            int numBoxes = box[0];
            int unitsPerBox = box[1];

            if (numBoxes <= truckSize) {
                truckSize -= numBoxes;
                totalUnits += numBoxes * unitsPerBox;
            } else {
                totalUnits += truckSize * unitsPerBox;
                truckSize = 0;
                break;
            }
        }

        return totalUnits;
    }
};