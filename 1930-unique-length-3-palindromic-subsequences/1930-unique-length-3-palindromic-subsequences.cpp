class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> left(26, 0), right(26, 0);
        vector<unordered_set<char>> mid(26);

        for (char c : s) right[c - 'a']++;

        for (char c : s) {
            right[c - 'a']--;
            for (int ch = 0; ch < 26; ch++) {
                if (left[ch] > 0 && right[ch] > 0) {
                    mid[ch].insert(c);
                }
            }
            left[c - 'a']++;
        }

        int count = 0;
        for (int ch = 0; ch < 26; ch++) {
            count += mid[ch].size();
        }

        return count;
    }
};
