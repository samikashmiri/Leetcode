class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int index = 1;
        string word = "";
        for (char c : sentence) {
            if (c == ' ') {
                if (word.find(searchWord) == 0) return index;
                word = "";
                ++index;
            } else {
                word += c;
            }
        }
        return (word.find(searchWord) == 0) ? index : -1;
    }
};
