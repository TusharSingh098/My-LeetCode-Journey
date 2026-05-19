class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length()) return false;
        if (s == goal) return true;

        s += s;
        for (int i{0}; i < s.length() / 2; i++)
        {
            if (s[i] == goal[0])
            {
                int idx{i + 1};
                bool isGoal{true};
                for (int j{1}; j < goal.length(); j++)
                {
                    if (s[idx++] != goal[j])
                    {
                        isGoal = false;
                        break;
                    }
                }
                if (isGoal) return true;
            }
        }
        return false;
    }
};
