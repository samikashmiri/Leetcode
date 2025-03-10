class Solution {
public:
    string reverseWords(string s) {
       
        int left = 0, right = s.size() - 1;
        while (left <= right && s[left] == ' ') left++;
        while (left <= right && s[right] == ' ') right--;

        
        vector<string> words;
        string word;
        for (int i = left; i <= right; ++i) {
            if (s[i] != ' ') {
                word += s[i];
            } else if (!word.empty()) {
                words.push_back(word);
                word = "";
            }
        }
        if (!word.empty()) words.push_back(word); 

        
        reverse(words.begin(), words.end());
        string result;
        for (int i = 0; i < words.size(); ++i) {
            result += words[i];
            if (i < words.size() - 1) result += " ";
        }
        return result;
    }
};
