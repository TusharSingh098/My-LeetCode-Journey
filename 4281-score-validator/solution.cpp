class Solution {
public:
    vector<int> scoreValidator(vector<string>& events) {
        int score{0}, counter{0};
        int i{0};
        while (counter != 10 && i < events.size())
        {
            string ch = events[i];
            if (ch == "0") score += 0;
            else if (ch == "1") score += 1;
            else if (ch == "2") score += 2;
            else if (ch == "3") score += 3;
            else if (ch == "4") score += 4;
            else if (ch == "6") score += 6;
            else if (ch == "W") counter += 1;
            else if (ch == "WD") score += 1;
            else if (ch == "NB") score += 1;
            i++;
        }
        return {score, counter};
    }
};
