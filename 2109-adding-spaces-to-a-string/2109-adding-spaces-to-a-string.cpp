class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string result;
        int spaceIdx = 0, n = spaces.size();
        for (int i = 0; i < s.size(); ++i) {
            if (spaceIdx < n && i == spaces[spaceIdx]) {
                result += ' ';
                ++spaceIdx;
            }
            result += s[i];
        }
        return result;
    }
};
