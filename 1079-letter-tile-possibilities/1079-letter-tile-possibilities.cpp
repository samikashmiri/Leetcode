class Solution {
public:
    int numTilePossibilities(string tiles) {
        vector<int> count(26, 0);
        for (char tile : tiles) {
            count[tile - 'A']++;
        }
        return backtrack(count);
    }
    
private:
    int backtrack(vector<int>& count) {
        int total = 0;
        for (int i = 0; i < 26; i++) {
            if (count[i] > 0) {
                // Use this letter
                total++;
                count[i]--;
                // Explore further possibilities
                total += backtrack(count);
                // Backtrack to restore state
                count[i]++;
            }
        }
        return total;
    }
};
