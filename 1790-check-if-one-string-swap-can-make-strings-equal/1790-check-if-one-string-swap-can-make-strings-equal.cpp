class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        // Store indices where s1 and s2 differ
        vector<int> diff;
        
        // Compare characters in both strings
        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] != s2[i]) {
                diff.push_back(i);
            }
        }
        
        // If no differences, strings are already equal
        if (diff.size() == 0) {
            return true;
        }
        
    
        if (diff.size() == 2) {
            return (s1[diff[0]] == s2[diff[1]] && s1[diff[1]] == s2[diff[0]]);
        }
        

        return false;
    }
};
