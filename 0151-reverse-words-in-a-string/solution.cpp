class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();

        int left{0}, right = n - 1;
        while (left < right) swap(s[left++], s[right--]);

        int idx{0};
        for (int i{0}; i < n; i++)
        {
            if (s[i] != ' ')
            {
                if (idx != 0) s[idx++] = ' ';

                int start{idx};
                while (i < n && s[i] != ' ') s[idx++] = s[i++];

                left = start, right = idx - 1;
                while (left < right) swap(s[left++], s[right--]);
            }
        }
        s.resize(idx);
        return s;
    }
};
