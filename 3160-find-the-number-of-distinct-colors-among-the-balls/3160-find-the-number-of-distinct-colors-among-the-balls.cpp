class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> ball_to_color;
        unordered_map<int, int> color_count;
        vector<int> result;
        int distinct_colors = 0;
        
        for (const auto& query : queries) {
            int x = query[0];
            int y = query[1];
            
            if (ball_to_color.count(x)) {
                int old_color = ball_to_color[x];
                color_count[old_color]--;
                if (color_count[old_color] == 0) {
                    distinct_colors--;
                    color_count.erase(old_color);
                }
            }
            
            ball_to_color[x] = y;
            color_count[y]++;
            if (color_count[y] == 1) {
                distinct_colors++;
            }
            
            result.push_back(distinct_colors);
        }
        
        return result;
    }
};