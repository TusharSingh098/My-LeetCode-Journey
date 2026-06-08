class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        for (int i{0}; i < asteroids.size(); i++)
        {
            int curr{asteroids[i]};
            if (curr < 0 && i != 0)
            {
                while (!ans.empty())
                {
                    if (ans.back() < 0) break;
                    else if (ans.back() < abs(curr)) ans.pop_back();
                    else if  (ans.back() > abs(curr)) 
                    {
                        curr = 0;
                        break;
                    }
                    else 
                    {
                        ans.pop_back();
                        curr = 0;
                        break;
                    }
                }
            }
            if (curr != 0) ans.push_back(curr);
        }
        return ans;
    }
};