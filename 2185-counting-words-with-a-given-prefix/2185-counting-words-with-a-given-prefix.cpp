class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count = 0;
        for (string& word : words) {
            if (word.find(pref) == 0) { // Check if 'pref' is a prefix
                count++;
            }
        }
        return count;
    }
};
