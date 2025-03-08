class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.length();
        int current_white = 0, min_operations;

        
        for (int i = 0; i < k; i++) {
            if (blocks[i] == 'W') {
                current_white++;
            }
        }

        min_operations = current_white;

        
        for (int i = k; i < n; i++) {
            
            if (blocks[i - k] == 'W') {
                current_white--;
            }
            if (blocks[i] == 'W') {
                current_white++;
            }

            
            min_operations = min(min_operations, current_white);
        }

        return min_operations;
    }
};
